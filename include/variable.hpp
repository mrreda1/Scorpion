#ifndef _VARIABLE
#define _VARIABLE

#include "token.hpp"

class T_var_ : public Token_ {
  private:
    inline static std::vector<T_var_ *> symbolTable;
    inline static std::unordered_map<string, size_t> nameToID;
    inline static size_t counter = 0;

    string name;
    size_t id;

  protected:
    T_data_type data_type;

    T_var_(string name) {
        symbolTable.push_back(this);
        nameToID[name] = counter;
        this->name = name;
        this->id = counter++;
        this->token_type = Identifier;
    }

  public:
    T_data_type getDataType() {
        return data_type;
    }
    size_t getID() {
        return id;
    }
    string getName() {
        return name;
    }
    static size_t getID(string name) {
        return nameToID[name];
    }
    static T_var_ *getVariable(string name) {
        return getVariable(getID(name));
    }
    static T_var_ *getVariable(size_t id) {
        return symbolTable[id];
    }

    virtual ~T_var_() = default;
};

using T_var = T_var_ *;

class T_Integer_ : public T_var_ {
  private:
    int value;

  public:
    T_Integer_(string name, int value = 0) : T_var_(name) {
        this->data_type = Integer;
        this->value = value;
    }
    int getValue() {
        return value;
    }
    void setValue(int value) {
        this->value = value;
    }
};

using T_Integer = T_Integer_ *;

class T_Character_ : public T_var_ {
  private:
    char value;

  public:
    T_Character_(string name, char value = 0) : T_var_(name) {
        this->data_type = Character;
        this->value = value;
    }
    char getValue() {
        return value;
    }
    void setValue(char value) {
        this->value = value;
    }
};

using T_Character = T_Character_ *;

class T_String_ : public T_var_ {
  private:
    string value;

  public:
    T_String_(string name, string value = "") : T_var_(name) {
        this->data_type = String;
        this->value = value;
    }
    string getValue() {
        return value;
    }
    void setValue(string value) {
        this->value = value;
    }
};

using T_String = T_String_ *;

class T_Float_ : public T_var_ {
  private:
    float value;

  public:
    T_Float_(string name, float value = 0) : T_var_(name) {
        this->data_type = Float;
        this->value = value;
    }
    float getValue() {
        return value;
    }
    void setValue(float value) {
        this->value = value;
    }
};

using T_Float = T_Float_ *;

#endif
