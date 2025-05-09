#ifndef _OPERATOR
#define _OPERATOR

#include "token.hpp"

class T_operator_ : public Token_ {
  private:
    T_operator_category operator_category;
    T_operator_type operator_type;

  public:
    T_operator_(T_operator_type operator_type, int line) {
        this->line = line;
        this->token_type = Operator;
        this->operator_type = operator_type;
        this->operator_category = operator_category_table[operator_type];
    }
    T_operator_type getOperatorType() {
        return operator_type;
    }
    T_operator_category getOperatorCategory() {
        return operator_category;
    }
};

using T_operator = T_operator_ *;


#endif
