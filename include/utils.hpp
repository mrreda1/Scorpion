#ifndef _UTILS
#define _UTILS

#include <array>
#include <iostream>
#include <regex>
#include <unordered_map>
#include <vector>

using std::vector;
using std::string;
using std::unordered_map;

enum T_token_type {
    Identifier,
    Condition,
    TypeSpeciefier,
    Void,
    Loop,
    Return,
    Struct,
    Operator,
    Braces,
    Constant,
    QuotationSingle,
    QuotationDouble,
    ContentString,
    Inclusion,
    CommentOneLine,
    CommentBegin,
    CommentEnd,
    EndStatement,
    Comma
};

enum T_content_string_type { QDContent, QSContent, CMContent, COLContent };

enum T_operator_category {
    ArithmeticOper,
    LogicOper,
    RelationalOper,
    AssignmentOper,
    AccessOper
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

// enum T_condition_type { If_branch, Else_branch };
enum T_data_type { Integer, Character, String, Float, SInteger, SFloat };
enum T_braces_type { Parenthesis, CurlyBrackets, Brackets };
enum T_comment_type { Multiple, OneLine };
enum T_loop_type { RepeatWhen, Reiterate };
enum T_braces_dir { Open, Close };

#endif
