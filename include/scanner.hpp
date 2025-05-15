#ifndef _SCANNER
#define _SCANNER

#include "braces.hpp"
#include "condition.hpp"
#include "constant.hpp"
#include "contentstring.hpp"
#include "identifier.hpp"
#include "keywords.hpp"
#include "loop.hpp"
#include "operator.hpp"
#include "token.hpp"
#include "typespecifier.hpp"
#include "utils.hpp"


std::tuple<std::vector<Token>, int, int> scan(std::string);
std::string tokenString(Token token);
std::array<string, 2> tokenInfo(Token token);
int to_int(std::string num);


#endif
