#ifndef _VARIABLE
#define _VARIABLE
#include "token.hpp"

class T_var : public Token {
  private:
    inline static size_t counter = 0;
    size_t id;

  protected:
    T_data_type data_type;
    T_var() {
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
    virtual ~T_var() = default;
};

class T_Integer : public T_var {
  private:
    int value;

  public:
    T_Integer(int value) : T_var() {
        this->data_type = Integer;
        this->value = value;
    }
    int getValue() {
        return value;
    }
};

class T_SInteger : public T_var {
  private:
    T_sign sign;
    int value;

  public:
    T_SInteger(int value, T_sign sign) : T_var() {
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

class T_Character : public T_var {
  private:
    char value;

  public:
    T_Character(char value) : T_var() {
        this->data_type = Character;
        this->value = value;
    }
    char getValue() {
        return value;
    }
};

class T_String : public T_var {
  private:
    string value;

  public:
    T_String(string value) : T_var() {
        this->data_type = String;
        this->value = value;
    }
    string getValue() {
        return value;
    }
};

class T_Float : public T_var {
  private:
    float value;

  public:
    T_Float(float value) : T_var() {
        this->data_type = Float;
        this->value = value;
    }
    float getValue() {
        return value;
    }
};

class T_SFloat : public T_var {
  private:
    T_sign sign;
    float value;

  public:
    T_SFloat(float value, T_sign sign) : T_var() {
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
#endif
