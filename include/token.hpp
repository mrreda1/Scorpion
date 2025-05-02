#ifndef _TOKEN
#define _TOKEN
#include "utils.hpp"

class Token {
  protected:
    T_token_type token_type;
    Token() {};

  public:
    T_token_type getTokenType() {
        return token_type;
    }
    virtual ~Token() = default;
};
#endif
