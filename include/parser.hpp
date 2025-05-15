#include "scanner.hpp"
#include "utils.hpp"

bool args(vector<Token> &tokens, int itr, int state = 0);
bool multi_line_comment(vector<Token> &tokens, int itr, int state = 0);
bool one_line_comment(vector<Token> &tokens, int itr, int state = 0);
bool include_rule(vector<Token> &tokens, int itr, int state = 0);
bool params(vector<Token> &tokens, int itr, int state = 0);
bool call(vector<Token> &tokens, int itr, int state = 0);
