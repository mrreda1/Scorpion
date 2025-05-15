#ifndef _KEYWORDS
#define _KEYWORDS

#include "utils.hpp"

static unordered_map<T_token_type, string>
    token_print_table({{Identifier, "Identifier"},
                       {Condition, "Condition"},
                       {TypeSpeciefier, "Type Specifier"},
                       {Void, "Void"},
                       {Loop, "Loop"},
                       {Return, "Return"},
                       {Struct, "Struct"},
                       {Operator, "Operator"},
                       {Braces, "Braces"},
                       {Constant, "Constant"},
                       {QuotationSingle, "Single Quotation"},
                       {QuotationDouble, "Double Quotation"},
                       {Inclusion, "Inclusion"},
                       {CommentBegin, "Comment Start"},
                       {CommentEnd, "Comment End"},
                       {CommentOneLine, "Comment"},
                       {EndStatement, "Semi Column"},
                       {Comma, "Comma"}

    });

static unordered_map<T_token_type, string>
    keyword_print_table({{Void, "NOReturn"},
                         {Return, "Turnback"},
                         {Struct, "Loli"},
                         {QuotationSingle, "'"},
                         {QuotationDouble, "\""},
                         {Inclusion, "Include"},
                         {CommentBegin, "/@"},
                         {CommentEnd, "@/"},
                         {CommentOneLine, "/^"},
                         {EndStatement, ";"},
                         {Comma, ","}

    });

static unordered_map<T_loop_type, string>
    loop_print_table({{RepeatWhen, "RepeatWhen"}, {Reiterate, "Reiterate"}});

static unordered_map<T_content_string_type, string> content_string_print_table{
    {COLContent, "One-line Comment Content"},
    {CMContent, "Multi-line Comment Content"},
    {QDContent, "Double Quotation Content"},
    {QSContent, "Single Quotation Content"},
};

static unordered_map<T_operator_category, string>
    operator_type_print_table({{ArithmeticOper, "Arithmetic Operator"},
                               {LogicOper, "Logical Operator"},
                               {RelationalOper, "Relational Operator"},
                               {AssignmentOper, "Assignment Operator"},
                               {AccessOper, "Access Operator"}});

static unordered_map<T_operator_type, string>
    operator_print_table({{SumOper, "+"},
                          {SubOper, "-"},
                          {MulOper, "*"},
                          {DivOper, "/"},
                          {LAndOper, "&&"},
                          {LOrOper, "||"},
                          {NotOper, "~"},
                          {IsEqOper, "=="},
                          {LessOper, "<"},
                          {GreaterOper, ">"},
                          {NotEqOper, "!="},
                          {LEOper, "<="},
                          {GEOper, ">="},
                          {EqualOper, "="},
                          {PointerOper, "->"}});

static unordered_map<T_data_type, string>
    type_specifier_print_table({{Integer, "Imw"},
                                {SInteger, "SIMw"},
                                {Character, "Chj"},
                                {String, "Series"},
                                {Float, "IMwf"},
                                {SFloat, "SIMwf"}});

static unordered_map<string, T_token_type>
    keyword_table({{"IfTrue", Condition},
                   {"Otherwise", Condition},
                   {"Imw", TypeSpeciefier},
                   {"SIMw", TypeSpeciefier},
                   {"Chj", TypeSpeciefier},
                   {"Series", TypeSpeciefier},
                   {"IMwf", TypeSpeciefier},
                   {"SIMwf", TypeSpeciefier},
                   {"NOReturn", Void},
                   {"RepeatWhen", Loop},
                   {"Reiterate", Loop},
                   {"Turnback", Return},
                   {"Loli", Struct},
                   {"Include", Inclusion},
                   {"+", Operator},
                   {"-", Operator},
                   {"*", Operator},
                   {"/", Operator},
                   {"&&", Operator},
                   {"||", Operator},
                   {"~", Operator},
                   {"==", Operator},
                   {"<", Operator},
                   {">", Operator},
                   {"!=", Operator},
                   {"<=", Operator},
                   {">=", Operator},
                   {"=", Operator},
                   {"->", Operator},
                   {"{", Braces},
                   {"}", Braces},
                   {"[", Braces},
                   {"]", Braces},
                   {"(", Braces},
                   {")", Braces},
                   {";", EndStatement},
                   {",", Comma},
                   {"\"", QuotationDouble},
                   {"'", QuotationSingle},
                   {"/@", CommentBegin},
                   {"@/", CommentEnd},
                   {"/^", CommentOneLine}});

static unordered_map<T_operator_type, T_operator_category>
    operator_category_table({{SumOper, ArithmeticOper},
                             {SubOper, ArithmeticOper},
                             {MulOper, ArithmeticOper},
                             {DivOper, ArithmeticOper},
                             {LAndOper, LogicOper},
                             {LOrOper, LogicOper},
                             {NotOper, LogicOper},
                             {IsEqOper, RelationalOper},
                             {LessOper, RelationalOper},
                             {GreaterOper, RelationalOper},
                             {NotEqOper, RelationalOper},
                             {LEOper, RelationalOper},
                             {GEOper, RelationalOper},
                             {EqualOper, AssignmentOper},
                             {PointerOper, AccessOper}});

static unordered_map<string, T_operator_type>
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

static unordered_map<string, T_braces_type>
    braces_type_table({{"{", CurlyBrackets},
                       {"[", Brackets},
                       {"(", Parenthesis},
                       {"}", CurlyBrackets},
                       {"]", Brackets},
                       {")", Parenthesis}});

static unordered_map<string, T_data_type>
    type_specifier_table({{"Imw", Integer},
                          {"SIMw", SInteger},
                          {"Chj", Character},
                          {"Series", String},
                          {"IMwf", Float},
                          {"SIMwf", SFloat}});

static unordered_map<string, T_loop_type>
    loop_table({{"RepeatWhen", RepeatWhen}, {"Reiterate", Reiterate}});

static const string IF_BRANCH = "IfTrue";
static const string ELSE_BRANCH = "Otherwise";
static const string ONE_LINE_COMMENT = "/^";
static const string OPEN_BRACES = "{[(";
// const string CLOSE_BRACES = "}])";

#endif
