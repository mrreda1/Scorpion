#include "../include/scanner.hpp"

using std::array;
using std::string;
using std::to_string;

int to_int(string num) {
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

string tokenString(Token token) {
    switch (token->getTokenType()) {
        case Identifier: {
            T_identifier identifier = dynamic_cast<T_identifier>(token);
            return identifier->getIdentifier();
        }
        case Condition: {
            T_condition condition = dynamic_cast<T_condition>(token);
            return condition->isIfBranch() ? IF_BRANCH : ELSE_BRANCH;
        }
        case TypeSpeciefier: {
            T_type_specifier type_specifier =
                dynamic_cast<T_type_specifier>(token);
            return type_specifier_print_table[type_specifier->getDataType()];
        }
        case Loop: {
            T_loop loop = dynamic_cast<T_loop>(token);
            return loop_print_table[loop->getLoopType()];
        }
        case Operator: {
            T_operator oper = dynamic_cast<T_operator>(token);
            return operator_print_table[oper->getOperatorType()];
        }
        case ContentString: {
            T_content_string str = dynamic_cast<T_content_string>(token);
            return str->getContentString();
        }
        case Braces: {
            T_braces braces = dynamic_cast<T_braces>(token);
            T_braces_type braces_type = braces->getBracesType();
            bool is_open = braces->isOpenBraces();

            switch (braces_type) {
                case Parenthesis:
                    return is_open ? "(" : ")";
                case Brackets:
                    return is_open ? "[" : "]";
                case CurlyBrackets:
                    return is_open ? "{" : "}";
            }
        }
        case Constant: {
            T_constant constant = dynamic_cast<T_constant>(token);
            return to_string(constant->getValue());
        }
        default: {
            return keyword_print_table[token->getTokenType()];
        }
    }
}

array<string, 2> tokenInfo(Token token) {
    int line = token->getLine();
    string text = tokenString(token);
    string token_log_text = "Line: " + to_string(line) + string(2, ' ');
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
            token_log_type =
                string("Token Type: ") +
                operator_type_print_table[oper->getOperatorCategory()];
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
