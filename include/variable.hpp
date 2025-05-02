#ifndef _VARIABLE
#define _VARIABLE
#include "token.hpp"

class T_var_ : public Token_ {
  private:
    inline static size_t counter = 0;
    size_t id;

  protected:
    T_data_type data_type;
    T_var_() {
        this->id = counter++;
        this->token_type = Variable;
    }

  public:
    T_data_type getDataType() {
        return data_type;
    }
    size_t getID() {
        return id;
    }
    virtual ~T_var_() = default;
};
using T_var = T_var_ *;

class T_Integer_ : public T_var_ {
  private:
    int value;

  public:
    T_Integer_(int value) : T_var_() {
        this->data_type = Integer;
        this->value = value;
    }
    int getValue() {
        return value;
    }
};
using T_Integer = T_Integer_ *;

class T_SInteger_ : public T_var_ {
  private:
    T_sign sign;
    int value;

  public:
    T_SInteger_(int value, T_sign sign) : T_var_() {
        this->data_type = SInteger;
        this->value = value;
        this->sign = sign;
    }
    int getValue() {
        return value;
    }
    T_sign getSign() {
        return sign;
    }
};
using T_SInteger = T_SInteger_ *;

class T_Character_ : public T_var_ {
  private:
    char value;

  public:
    T_Character_(char value) : T_var_() {
        this->data_type = Character;
        this->value = value;
    }
    char getValue() {
        return value;
    }
};
using T_Character = T_Character_ *;

class T_String_ : public T_var_ {
  private:
    string value;

  public:
    T_String_(string value) : T_var_() {
        this->data_type = String;
        this->value = value;
    }
    string getValue() {
        return value;
    }
};
using T_String = T_String_ *;

class T_Float_ : public T_var_ {
  private:
    float value;

  public:
    T_Float_(float value) : T_var_() {
        this->data_type = Float;
        this->value = value;
    }
    float getValue() {
        return value;
    }
};
using T_Float = T_Float_ *;

class T_SFloat_ : public T_var_ {
  private:
    T_sign sign;
    float value;

  public:
    T_SFloat_(float value, T_sign sign) : T_var_() {
        this->data_type = SFloat;
        this->value = value;
        this->sign = sign;
    }
    float getValue() {
        return value;
    }
    T_sign getSign() {
        return sign;
    }
};
using T_SFloat = T_SFloat_ *;
#endif
