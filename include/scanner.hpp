#ifndef _SCANNER
#define _SCANNER

#include "braces.hpp"
#include "condition.hpp"
#include "constant.hpp"
#include "identifier.hpp"
#include "keywords.hpp"
#include "operator.hpp"
#include "token.hpp"
#include "typespecifier.hpp"
#include "utils.hpp"


int to_int(string);
std::tuple<std::vector<Token>, std::vector<std::array<string, 2>>, int, int>
scan(std::string);

#endif
