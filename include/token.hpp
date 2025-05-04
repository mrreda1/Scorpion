#ifndef _TOKEN
#define _TOKEN

#include "keywords.hpp"
#include "utils.hpp"

class Token_ {
  protected:
    T_token_type token_type;
    Token_() {};

  public:
    Token_(T_token_type token_type) {
        this->token_type = token_type;
    }
    T_token_type getTokenType() {
        return token_type;
    }
    virtual ~Token_() = default;
};

using Token = Token_ *;

#endif
