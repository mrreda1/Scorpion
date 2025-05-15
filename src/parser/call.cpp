#include "../../include/parser.hpp"
#include <vector>

using std::vector;

bool call(vector<Token> &tokens, size_t itr, int state) {
    if (itr >= tokens.size()) {
        return false;
    }
    Token token = tokens[itr++];
    if (token->getTokenType() != Braces) {
        return false;
    }
    T_braces braces = dynamic_cast<T_braces>(token);
    if (!braces->isOpenBraces() &&
        braces->getBracesType() == Parenthesis) {
        return args(tokens, itr);
    }
    return false;
}
