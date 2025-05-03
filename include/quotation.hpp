#ifndef _QUOTATION
#define _QUOTATION

#include "token.hpp"

class T_quotation_double_ : public Token_ {
  private:
    string quotation_content;

  public:
    T_quotation_double_(string quotation_content) {
        this->token_type = QuotationDouble;
        this->quotation_content = quotation_content;
    }
    string getContent() {
        return quotation_content;
    }
};

using T_quotation_double = T_quotation_double_ *;

class T_quotation_single_ : public Token_ {
  private:
    char quotation_content;

  public:
    T_quotation_single_(char quotation_content) {
        this->token_type = QuotationSingle;
        this->quotation_content = quotation_content;
    }
    char getContent() {
        return quotation_content;
    }
};

using T_quotation_single = T_quotation_single_ *;

#endif
