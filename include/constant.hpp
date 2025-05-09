#ifndef _CONSTANT
#define _CONSTANT

#include "token.hpp"

class T_constant_ : public Token_ {
  private:
    int value;

  public:
    T_constant_(int value, int line) {
        this->line = line;
        this->token_type = Constant;
        this->value = value;
    }
    int getValue() {
        return value;
    }
};

using T_constant = T_constant_ *;

#endif
