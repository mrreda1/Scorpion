#ifndef _STRINGCONTENT
#define _STRINGCONTENT

#include "token.hpp"

class T_content_string_ : public Token_ {
  private:
    string content_string;
    T_content_string_type content_type;

  public:
    T_content_string_(string content_string,
                      T_content_string_type content_type, int line) {
        this->line = line;
        this->token_type = ContentString;
        this->content_string = content_string;
        this->content_type = content_type;
    }

    string getContentString() {
        return content_string;
    }

    T_content_string_type getContentType() {
        return content_type;
    }
};

using T_content_string = T_content_string_ *;

#endif
