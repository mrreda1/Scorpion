#include "../../include/parser.hpp"
#include <vector>

using std::vector;

bool multi_line_comment(vector<Token> &tokens, int itr, int state) {
    if (itr >= tokens.size()) {
        return false;
    }
    Token token = tokens[itr++];
    if (state == 0) {
        if (token->getTokenType() == ContentString) {
            return multi_line_comment(tokens, itr, state + 1);
        }
        return false;
    }
    return (token->getTokenType() == CommentEnd);
}

bool one_line_comment(vector<Token> &tokens, int itr, int state) {
    if (itr >= tokens.size()) {
        return false;
    }
    return (tokens[itr]->getTokenType() == ContentString);
}
