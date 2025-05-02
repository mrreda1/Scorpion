#include <iostream>
#include <vector>

using std::string;
using StmType = enum { A_compoundStm, A_assignStm, A_printStm };
using ExpType = enum { A_idExp, A_numExp, A_opExp, A_eseqExp };
using ExpListType = enum { A_pairExpList, A_lastExpList };
using A_binop = enum { A_plus, A_minus, A_mul, A_div };

class A_exp_ {
  protected:
    ExpType type;

  public:
    ExpType getType() {
        return type;
    }
};

using A_exp = A_exp_ *;
using A_expList = std::vector<A_exp> *;

class A_stm_ {
  protected:
    StmType type;

  public:
    StmType getType() {
        return type;
    }
};

using A_stm = A_stm_ *;

class A_IdExp : A_exp_ {
  private:
    string id;

  public:
    A_IdExp(string id) {
        this->type = A_idExp;
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
        this->type = A_numExp;
        this->num = num;
    }
    int getNum() {
        return num;
    }
};

class A_EseqExp : A_exp_ {
  private:
    A_stm stm;
    A_exp exp;

  public:
    A_EseqExp(A_stm stm, A_exp exp) {
        this->type = A_eseqExp;
        this->stm = stm;
        this->exp = exp;
    }
    A_stm getStm() {
        return stm;
    }
    A_exp getExp() {
        return exp;
    }
};

class A_OpExp : A_exp_ {
  private:
    A_exp left, right;
    A_binop oper;

  public:
    A_OpExp(A_exp left, A_exp right, A_binop oper) {
        this->type = A_opExp;
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

class A_CompoundStm : A_stm_ {
  private:
    A_stm left, right;

  public:
    A_CompoundStm(A_stm left, A_stm right) {
        this->type = A_compoundStm;
        this->left = left;
        this->right = right;
    }
    A_stm getLeft() {
        return left;
    }
    A_stm getRight() {
        return right;
    }
};

class A_AssignStm : A_stm_ {
  private:
    string id;
    A_exp exp;

  public:
    A_AssignStm(string id, A_exp exp) {
        this->type = A_assignStm;
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
    A_expList exps;

  public:
    A_PrintStm(A_expList exps) {
        this->type = A_printStm;
        this->exps = exps;
    }
    A_expList getExpList() {
        return exps;
    }
};
