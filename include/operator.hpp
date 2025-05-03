#ifndef _OPERATOR
#define _OPERATOR

#include "token.hpp"

class T_operator_ : public Token_ {
  private:
    T_operator_type operator_type;

  public:
    T_operator_(T_token_type token_type, T_operator_type operator_type)
        : Token_(token_type) {
        this->operator_type = operator_type;
    }
    T_operator_type getOperatorType() {
        return operator_type;
    }
};

using T_operator = T_operator_ *;


#endif
