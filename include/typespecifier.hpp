#ifndef _TYPESPECIFIER
#define _TYPESPECIFIER

#include "token.hpp"

class T_type_specifier_ : public Token_ {
  private:
    T_data_type data_type;

  public:
    T_type_specifier_(T_data_type data_type) {
        this->token_type = TypeSpeciefier;
        this->data_type = data_type;
    }
    T_data_type getDataType() {
        return data_type;
    }
};

using T_type_specifier = T_type_specifier_ *;

#endif
