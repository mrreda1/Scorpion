#ifndef _LOOP
#define _LOOP

#include "token.hpp"

class T_loop_ : public Token_ {
  private:
    T_loop_type loop_type;

  public:
    T_loop_(T_loop_type loop_type, int line) {
        this->line = line;
        this->token_type = Loop;
        this->loop_type = loop_type;
    }
    T_loop_type getLoopType() {
        return loop_type;
    }
};

using T_loop = T_loop_ *;

#endif
