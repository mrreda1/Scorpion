#ifndef _BRACES
#define _BRACES

#include "token.hpp"

class T_braces_ : public Token_ {
  private:
    T_braces_type braces_type;
    bool is_open_braces;

  public:
    T_braces_(T_braces_type braces_type, bool is_open_braces) {
        this->token_type = Braces;
        this->braces_type = braces_type;
        this->is_open_braces = is_open_braces;
    }
    T_braces_type getBracesType() {
        return braces_type;
    }
    bool isOpenBraces() {
        return is_open_braces;
    }
};

using T_braces = T_braces_ *;

#endif
