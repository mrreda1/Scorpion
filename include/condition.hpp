#ifndef _CONDITION
#define _CONDITION

#include "token.hpp"

class T_condition_ : public Token_ {
  private:
    bool is_if_branch;

  public:
    T_condition_(bool is_if_branch) {
        this->token_type = Condition;
        this->is_if_branch = is_if_branch;
    }
    bool isIfBranch() {
        return is_if_branch;
    }
};

using T_condition = T_condition_ *;

#endif
