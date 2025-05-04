#include "../include/scanner.hpp"
#include <array>
#include <fstream>
using std::to_string;

int to_int(std::string num) {
    int power = 1, res = 0;
    reverse(num.begin(), num.end());
    for (char digit : num) {
        if (digit < '0' || digit > '9') {
            return -1;
        }
        res += (digit - '0') * power;
        power *= 10;
    }
    return res;
}

int getNewState(char c) {
    switch (c) {
        case '<':
            return 1;
        case '>':
            return 2;
        case '-':
            return 3;
        case '=':
            return 4;
        case '/':
            return 5;
        default:
            return 0;
    }
}

std::array<string, 2> tokenLog(Token token, int line, string text) {
    string token_log_text = "Line: " + to_string(line) + string(1, '\t');
    string token_log_type;
    switch (token->getTokenType()) {
        case Identifier: {
            T_identifier identifier = dynamic_cast<T_identifier>(token);
            token_log_text +=
                string((identifier->isValid() ? "" : "Error in ")) +
                string("Token Text: ") + text;
            token_log_type = string("Token Type: ") +
                             string((identifier->isValid() ? "" : "Invalid ")) +
                             string("Identifier");
        } break;
        case Operator: {
            T_operator oper = dynamic_cast<T_operator>(token);
            token_log_text += string("Token Text: ") + text;
            token_log_type = string("Token Type: ") +
                             operator_print_table[oper->getOperatorCategory()];
        } break;
        case ContentString: {
            T_content_string content = dynamic_cast<T_content_string>(token);
            token_log_text += string("Token Text: ") + text;
            token_log_type =
                string("Token Type: ") +
                content_string_print_table[content->getContentType()];
        } break;
        default:
            token_log_text += string("Token Text: ") + text;
            token_log_type = string("Token Type: ") +
                             token_print_table[token->getTokenType()];
    }
    return {token_log_text, token_log_type};
}
Token makeNewToken(std::string identifier, int &errors) {
    if (int num = to_int(identifier) != -1) {
        return new T_constant_(num);
    } else if (keyword_table.find(identifier) != keyword_table.end()) {
        T_token_type token_type = keyword_table[identifier];
        switch (token_type) {
            case TypeSpeciefier:
                return new T_type_specifier_(type_specifier_table[identifier]);
            case Condition:
                return new T_condition_(identifier == IF_BRANCH);
            case Operator:
                return new T_operator_(operator_type_table[identifier]);
            case Braces:
                return new T_braces_(braces_type_table[identifier],
                                     OPEN_BRACES.find(identifier) !=
                                         std::string::npos);
            default:
                return new Token_(token_type);
        }
    } else if (!identifier.empty()) {
        T_identifier new_token = new T_identifier_(identifier);
        errors += !new_token->isValid();
        return new_token;
    }
    return nullptr;
}

std::tuple<std::vector<Token>, std::vector<std::array<string, 2>>, int, int>
scan(std::string path) {
    std::ifstream source(path);
    char current;

    std::vector<std::array<string, 2>> scanner_log;
    std::vector<Token> tokens;
    int line = 1;
    int errors = 0;
    int state = 0;

    std::string prefix = "";
    std::string terminate = "><*+,;-={}()[]/~\"' \n\t";
    std::string spaces = " \n\t";

    while (source.get(current)) {
        if (state == 0 && !prefix.empty() &&
            terminate.find(current) != std::string::npos) {
            if (prefix != "") {
                Token new_token = makeNewToken(prefix, errors);
                tokens.push_back(new_token);
                scanner_log.push_back(tokenLog(new_token, line, prefix));
                prefix = "";
            }
        }
        switch (state) {
            case 0:
                state = getNewState(current);
                if (state == 0 && !prefix.empty()) {
                    if (current == '|' && prefix.back() == '|') {
                        prefix.pop_back();
                        if (prefix != "") {
                            Token new_token = makeNewToken(prefix, errors);
                            tokens.push_back(new_token);
                            scanner_log.push_back(
                                tokenLog(new_token, line, prefix));
                            prefix = "";
                        }
                        Token new_token = new T_operator_(LOrOper);
                        tokens.push_back(new_token);
                        scanner_log.push_back(tokenLog(new_token, line, "||"));
                    } else if (current == '&' && prefix.back() == '&') {
                        prefix.pop_back();
                        if (prefix != "") {
                            Token new_token = makeNewToken(prefix, errors);
                            tokens.push_back(new_token);
                            scanner_log.push_back(
                                tokenLog(new_token, line, prefix));
                            prefix = "";
                        }
                        Token new_token = new T_operator_(LAndOper);
                        tokens.push_back(new_token);
                        scanner_log.push_back(tokenLog(new_token, line, "&&"));
                    } else if (spaces.find(current) == std::string::npos) {
                        prefix.push_back(current);
                    }
                } else if (state == 0) {
                    std::string currentstr(1, current);
                    if (keyword_table.find(currentstr) != keyword_table.end()) {
                        Token new_token = makeNewToken(currentstr, errors);
                        tokens.push_back(new_token);
                        scanner_log.push_back(
                            tokenLog(new_token, line, currentstr));
                    } else if (spaces.find(current) == std::string::npos) {
                        prefix.push_back(current);
                    }
                }
                break;
            case 1:
                if (current == '=') {
                    Token new_token = new T_operator_(LEOper);
                    tokens.push_back(new_token);
                    scanner_log.push_back(tokenLog(new_token, line, "<="));
                    state = 0;
                } else {
                    Token new_token = new T_operator_(LessOper);
                    tokens.push_back(new_token);
                    scanner_log.push_back(tokenLog(new_token, line, "<"));
                    state = getNewState(current);
                    if (state == 0) {
                        source.seekg(-1, std::ios::cur);
                    }
                }
                break;
            case 2:
                if (current == '=') {
                    Token new_token = new T_operator_(GEOper);
                    tokens.push_back(new_token);
                    scanner_log.push_back(tokenLog(new_token, line, ">="));
                    state = 0;
                } else {
                    Token new_token = new T_operator_(GreaterOper);
                    tokens.push_back(new_token);
                    scanner_log.push_back(tokenLog(new_token, line, ">"));
                    state = getNewState(current);
                    if (state == 0) {
                        source.seekg(-1, std::ios::cur);
                    }
                }
                break;
            case 3:
                if (current == '>') {
                    Token new_token = new T_operator_(PointerOper);
                    tokens.push_back(new_token);
                    scanner_log.push_back(tokenLog(new_token, line, "->"));
                    state = 0;
                } else {
                    Token new_token = new T_operator_(SubOper);
                    tokens.push_back(new_token);
                    scanner_log.push_back(tokenLog(new_token, line, "-"));
                    state = getNewState(current);
                    if (state == 0) {
                        source.seekg(-1, std::ios::cur);
                    }
                }
                break;
            case 4:
                if (current == '=') {
                    Token new_token = new T_operator_(IsEqOper);
                    tokens.push_back(new_token);
                    scanner_log.push_back(tokenLog(new_token, line, "=="));
                    state = 0;
                } else {
                    Token new_token = new T_operator_(EqualOper);
                    tokens.push_back(new_token);
                    scanner_log.push_back(tokenLog(new_token, line, "="));
                    state = getNewState(current);
                    if (state == 0) {
                        source.seekg(-1, std::ios::cur);
                    }
                }
                break;
            case 5: {
                if (current == '@') {
                    state = 0;
                } else if (current == '^') {
                    Token new_token = new Token_(CommentOneLine);
                    tokens.push_back(new_token);
                    scanner_log.push_back(tokenLog(new_token, line, "/^"));
                    while (source.get(current) && current != '\n') {
                        prefix.push_back(current);
                    }
                    if (!prefix.empty()) {
                        Token new_token =
                            new T_content_string_(prefix, COLContent);
                        tokens.push_back(new_token);
                        scanner_log.push_back(
                            tokenLog(new_token, line, prefix));
                    }
                    prefix = "";
                    state = 0;
                } else {
                    Token new_token = new T_operator_(DivOper);
                    tokens.push_back(new_token);
                    scanner_log.push_back(tokenLog(new_token, line, "/"));
                    state = getNewState(current);
                    if (state == 0) {
                        source.seekg(-1, std::ios::cur);
                    }
                }
            }
        }
        if (current == '\n') {
            line++;
        }
    }

    return {tokens, scanner_log, errors, line - 1};
}
