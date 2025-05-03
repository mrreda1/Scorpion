#ifndef _COMMENT
#define _COMMENT

#include "token.hpp"

class T_comment_ : public Token_ {
  private:
    T_comment_type comment_type;
    string comment_content;

  public:
    T_comment_(T_comment_type comment_type, string content) {
        this->token_type = Comment;
        this->comment_type = comment_type;
        this->comment_content = content;
    }
    T_comment_type getCommentType() {
        return comment_type;
    }
    string getCommentContent() {
        return comment_content;
    }
};

using T_comment = T_comment_ *;

#endif
