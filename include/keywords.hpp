#ifndef _KEYWORDS
#define _KEYWORDS

#include "utils.hpp"

std::unordered_map<string, T_token_type>
    keyword_table({{"IfTrue", Condition},
                   {"Otherwise", Condition},
                   {"Imw", TypeSpeciefier},
                   {"SIMw", TypeSpeciefier},
                   {"Chj", TypeSpeciefier},
                   {"Series", TypeSpeciefier},
                   {"IMwf", TypeSpeciefier},
                   {"SIMwf", TypeSpeciefier},
                   {"NOReturn", TypeSpeciefier},
                   {"RepeatWhen", Loop},
                   {"Reiterate", Loop},
                   {"Turnback", Return},
                   {"Loli", Struct},
                   {"+", ArithmeticOper},
                   {"-", ArithmeticOper},
                   {"*", ArithmeticOper},
                   {"/", ArithmeticOper},
                   {"&&", LogicOper},
                   {"||", LogicOper},
                   {"~", LogicOper},
                   {"==", RelationalOper},
                   {"<", RelationalOper},
                   {">", RelationalOper},
                   {"!=", RelationalOper},
                   {"<=", RelationalOper},
                   {">=", RelationalOper},
                   {"=", AssignmentOper},
                   {"->", AccessOper},
                   {"{", Braces},
                   {"}", Braces},
                   {"[", Braces},
                   {"]", Braces},
                   {"(", Braces},
                   {")", Braces},
                   {"Include", Inclusion},
                   {"/^", Comment},
                   {"/@", Comment},
                   {"@/", InvalidToken}});

std::unordered_map<string, T_operator_type>
    operator_type_table({{"+", SumOper},
                         {"-", SubOper},
                         {"*", MulOper},
                         {"/", DivOper},
                         {"&&", LAndOper},
                         {"||", LOrOper},
                         {"~", NotOper},
                         {"==", IsEqOper},
                         {"<", LessOper},
                         {">", GreaterOper},
                         {"!=", NotEqOper},
                         {"<=", LEOper},
                         {">=", GEOper},
                         {"=", EqualOper},
                         {"->", PointerOper}});

std::unordered_map<string, T_braces_type>
    braces_type_table({{"{", CurlyBrackets},
                       {"[", Brackets},
                       {"(", Parenthesis},
                       {"}", CurlyBrackets},
                       {"]", Brackets},
                       {")", Parenthesis}});

std::unordered_map<string, T_data_type> type_specifier_table({
    {"Imw", Integer},
    {"SIMw", Integer},
    {"Chj", Character},
    {"Series", String},
    {"IMwf", Float},
    {"SIMwf", Float},
    {"NOReturn", Void},
});

string ifBranch = "IfTrue";
string oneLineComment = "/^";
string open_braces = "{[(";
string close_braces = "}])";

#endif
