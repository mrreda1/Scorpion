#ifndef _BRACES
#define _BRACES

#include "token.hpp"

class T_braces_ : public Token_ {
  private:
    T_braces_type braces_type;
    T_braces_dir braces_dir;

  public:
    T_braces_(T_braces_type braces_type, T_braces_dir braces_dir) {
        this->token_type = Braces;
        this->braces_type = braces_type;
        this->braces_dir = braces_dir;
    }
    T_braces_type getBracesType() {
        return braces_type;
    }
    T_braces_dir getBracesDirection() {
        return braces_dir;
    }
};

using T_braces = T_braces_ *;

#endif
