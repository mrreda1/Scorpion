#ifndef _UTILS
#define _UTILS

#include <iostream>
#include <unordered_map>
#include <vector>

using std::string;

enum T_token_type {
    Variable,
    Condition,
    Integer,
    Character,
    String,
    Float,
    Void,
    Loop,
    Return,
    Struct,
    Operator,
    Braces,
    Constant,
    QuotationSingle,
    QuotationDouble,
    Inclusion,
    Comment
};

enum T_operator_type {
    Sum,
    Sub,
    Mul,
    Div,
    LAnd,
    LOr,
    Not,
    IsEq,
    Less,
    Greater,
    LE,
    GE,
    NotEq,
    Equal,
    Access
};

enum T_operator_category {
    ArithmeticOper,
    LogicOper,
    RelationalOper,
    AssignmentOper,
    AccessOper
};

enum T_data_type { D_Integer, D_Character, D_String, D_Float };
enum T_condition_type { If_branch, Else_branch };
enum T_braces_type { Parenthesis, CurlyBrackets, Brackets };
enum T_comment_type { Multiple, OneLine };
enum T_braces_dir { Open, Close };

#endif
