#include <iostream>
#include <vector>

using std::string;
using A_stm_type = enum { A_assign, A_print };
using A_exp_type = enum { A_id, A_num, A_oper };
using A_binop = enum { A_plus, A_minus, A_mul, A_div };

class A_exp_ {
  protected:
    A_exp_type type;

  public:
    A_exp_type getType() {
        return type;
    }
};

using A_exp = A_exp_ *;
using A_exp_list = std::vector<A_exp> *;

class A_stm_ {
  protected:
    A_stm_type type;

  public:
    A_stm_type getType() {
        return type;
    }
};

using A_stm = A_stm_ *;
using A_stm_list = std::vector<A_stm> *;

class A_IdExp : A_exp_ {
  private:
    string id;

  public:
    A_IdExp(string id) {
        this->type = A_id;
        this->id = id;
    }
    string getID() {
        return id;
    }
};

class A_NumExp : A_exp_ {
  private:
    int num;

  public:
    A_NumExp(int num) {
        this->type = A_num;
        this->num = num;
    }
    int getNum() {
        return num;
    }
};

class A_OpExp : A_exp_ {
  private:
    A_exp left, right;
    A_binop oper;

  public:
    A_OpExp(A_exp left, A_exp right, A_binop oper) {
        this->type = A_oper;
        this->left = left;
        this->right = right;
        this->oper = oper;
    }
    A_exp getLeft() {
        return left;
    }
    A_exp getRight() {
        return right;
    }
    A_binop getOper() {
        return oper;
    }
};

class A_AssignStm : A_stm_ {
  private:
    string id;
    A_exp exp;

  public:
    A_AssignStm(string id, A_exp exp) {
        this->type = A_assign;
        this->id = id;
        this->exp = exp;
    }
    string getID() {
        return id;
    }
    A_exp getExp() {
        return exp;
    }
};

class A_PrintStm : A_stm_ {
  private:
    A_exp_list exps;

  public:
    A_PrintStm(A_exp_list exps) {
        this->type = A_print;
        this->exps = exps;
    }
    A_exp_list getExpList() {
        return exps;
    }
};
