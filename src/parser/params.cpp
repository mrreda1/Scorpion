#include "../../include/parser.hpp"
#include <vector>

using std::vector;

bool params(vector<Token> &tokens, int itr, int state) {
    if (itr >= tokens.size()) {
        return false;
    }
    Token token = tokens[itr++];
    switch (state) {
        case 0: {
            if (token->getTokenType() == TypeSpeciefier) {
                return params(tokens, itr, 1);
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
            if (token->getTokenType() != Identifier) {
                return false;
            }
            T_identifier identifier = dynamic_cast<T_identifier>(token);
            if (identifier->isValid()) {
                return params(tokens, itr, 2);
            }
            return false;
        }
        case 2: {
            if (token->getTokenType() == Comma) {
                return params(tokens, itr, 3);
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
        case 3: {
            if (token->getTokenType() == TypeSpeciefier) {
                return params(tokens, itr, 1);
            }
        }
    }
    return false;
}
