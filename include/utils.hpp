#ifndef _UTILS
#define _UTILS

#include <iostream>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;

enum T_token_type {
    InvalidToken,
    InvalidIdentifier,
    Identifier,
    Condition,
    TypeSpeciefier,
    Loop,
    Return,
    Struct,
    ArithmeticOper,
    LogicOper,
    RelationalOper,
    AssignmentOper,
    AccessOper,
    Braces,
    Constant,
    QuotationSingle,
    QuotationDouble,
    Inclusion,
    Comment,
    EndStatement,
    Comma
};

enum T_operator_type {
    SumOper,
    SubOper,
    MulOper,
    DivOper,
    LAndOper,
    LOrOper,
    NotOper,
    IsEqOper,
    LessOper,
    GreaterOper,
    LEOper,
    GEOper,
    NotEqOper,
    EqualOper,
    PointerOper
};

enum T_data_type { Integer, Character, String, Float, Void };
enum T_condition_type { If_branch, Else_branch };
enum T_braces_type { Parenthesis, CurlyBrackets, Brackets };
enum T_comment_type { Multiple, OneLine };
enum T_braces_dir { Open, Close };

#endif
