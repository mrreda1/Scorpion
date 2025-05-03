#ifndef _CONDITION
#define _CONDITION

#include "token.hpp"

class T_condition_ : public Token_ {
  private:
    T_condition_type condition_type;

  public:
    T_condition_(T_condition_type condition_type) {
        this->token_type = Condition;
        this->condition_type = condition_type;
    }
    T_condition_type getConditionType() {
        return condition_type;
    }
};

using T_condition = T_condition_ *;

#endif
