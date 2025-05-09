#ifndef _TOKEN
#define _TOKEN

#include "keywords.hpp"
#include "utils.hpp"

class Token_ {
  protected:
    T_token_type token_type;
    int line;
    Token_() {};

  public:
    Token_(T_token_type token_type, int line) {
        this->line = line;
        this->token_type = token_type;
    }
    T_token_type getTokenType() {
        return token_type;
    }
    int getLine() {
        return line;
    }
    virtual ~Token_() = default;
};

using Token = Token_ *;

#endif
