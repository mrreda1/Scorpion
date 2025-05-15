#include "../../include/parser.hpp"
#include <vector>

using std::vector;

bool include_command(vector<Token> &tokens, size_t itr, int state) {
    if (itr >= tokens.size()) {
        return false;
    }
    Token token = tokens[itr++];
    switch (state) {
        case 0: {
            if (token->getTokenType() != Braces) {
                return false;
            }
            T_braces braces = dynamic_cast<T_braces>(token);
            if (braces->isOpenBraces() &&
                braces->getBracesType() == Parenthesis) {
                return include_command(tokens, itr, 1);
            }
            return false;
        }
        case 1: {
            if (token->getTokenType() == Identifier) {
                return include_command(tokens, itr, 2);
            }
            return false;
        }
        case 2: {
            if (token->getTokenType() != Braces) {
                return false;
            }
            T_braces braces = dynamic_cast<T_braces>(token);
            if (!braces->isOpenBraces() &&
                braces->getBracesType() == Parenthesis) {
                return include_command(tokens, itr, 3);
            }
            return false;
        }
    }
    return (token->getTokenType() == EndStatement);
}
