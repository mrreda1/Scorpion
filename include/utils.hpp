#ifndef _UTILS
#define _UTILS
#include <iostream>
using std::string;
using T_token_type = enum {
    Variable,
    Condition,
    Void,
    Loop,
    Return,
    Struct,
    ArithmeticOper,
    LogicalOper,
    RelationalOper,
    AssignmentOper,
    AccessOper,
    Braces,
    Constant,
    QuotationMark,
    Inclusion,
    Comment
};
using T_data_type = enum {
    Integer,
    SInteger,
    Character,
    String,
    Float,
    SFloat
};
using T_sign = enum { positive, negative };
#endif
