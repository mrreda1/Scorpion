#ifndef _IDENTIFIER
#define _IDENTIFIER

#include "token.hpp"

static const std::regex identifier_regex("^[A-Za-z_][A-Za-z0-9_]*$");
class T_identifier_ : public Token_ {
  private:
    string identifier;
    bool is_valid;

  public:
    T_identifier_(string identifier, int line) {
        this->line = line;
        this->token_type = Identifier;
        this->identifier = identifier;
        this->is_valid = isValidIdentifier(identifier);
    }
    static bool isValidIdentifier(string identifier) {
        return std::regex_match(identifier, identifier_regex);
    }
    string getIdentifier() {
        return identifier;
    }
    bool isValid() {
        return is_valid;
    }
};

using T_identifier = T_identifier_ *;

#endif
