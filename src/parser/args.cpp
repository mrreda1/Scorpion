#include "../../include/parser.hpp"
#include <vector>

using std::vector;

bool args(vector<Token> &tokens, int itr, int state) {
    if (itr >= tokens.size()) {
        return false;
    }
    Token token = tokens[itr++];
    switch (state) {
        case 0: {
            if (token->getTokenType() == Identifier) {
                T_identifier identifier = dynamic_cast<T_identifier>(token);
                if (identifier->isValid()) {
                    return args(tokens, itr, 1);
                }
                return false;
            }
            if (token->getTokenType() != Braces) {
                return false;
            }
            T_braces braces = dynamic_cast<T_braces>(token);
            if (!braces->isOpenBraces() &&
                braces->getBracesType() == Parenthesis) {
                return true;
            }
            return false;
        }
        case 1: {
            if (token->getTokenType() == Comma) {
                return args(tokens, itr, 2);
            }
            if (token->getTokenType() != Braces) {
                return false;
            }
            T_braces braces = dynamic_cast<T_braces>(token);
            if (!braces->isOpenBraces() &&
                braces->getBracesType() == Parenthesis) {
                return true;
            }
            return false;
        }
        case 2: {
            if (token->getTokenType() != Identifier) {
                return false;
            }
            T_identifier identifier = dynamic_cast<T_identifier>(token);
            if (identifier->isValid()) {
                return args(tokens, itr, 1);
            }
        }
    }
    return false;
}
