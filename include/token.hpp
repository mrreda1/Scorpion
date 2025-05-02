#ifndef _TOKEN
#define _TOKEN
#include "utils.hpp"

class Token_ {
  protected:
    T_token_type token_type;
    Token_() {};

  public:
    T_token_type getTokenType() {
        return token_type;
    }
    virtual ~Token_() = default;
};
using Token = Token_ *;
#endif
