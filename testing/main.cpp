#include "../include/scanner.hpp"
#include <vector>

using namespace std;

int main() {
    vector<Token> tokens;
    T_Character var_c = new T_Character_("c", 'a');
    T_Integer var_x = new T_Integer_("x", 4543);
    T_Integer var_y = new T_Integer_("y");
    T_braces br = new T_braces_(Parenthesis, Open);

    tokens.push_back(var_c);
    tokens.push_back(var_x);
    tokens.push_back(var_y);
    tokens.push_back(br);

    for (Token token : tokens) {
        switch (token->getTokenType()) {
            case Identifier: {
                T_var var = dynamic_cast<T_var>(token);
                cout << "\nID: " << var->getID() << '\n';
                cout << "Name: " << var->getName() << '\n';
                switch (var->getDataType()) {
                    case Character: {
                        T_Character char_var = dynamic_cast<T_Character>(var);
                        cout << "Type: Character\n";
                        cout << "Char: " << char_var->getValue() << '\n';
                    } break;
                    case Integer: {
                        T_Integer int_var = dynamic_cast<T_Integer>(var);
                        cout << "Type: Integer\n";
                        cout << "Value: " << int_var->getValue() << '\n';
                    } break;
                }


            } break;
            case Braces: {
                T_braces brace = dynamic_cast<T_braces>(token);
                cout << "\nToken type: Braces\n";
                cout << "Braces type: " << (brace->getBracesType() == Parenthesis ? "Parenthesis\n" : "\n");
                cout << "Braces direction: " << (brace->getBracesDirection() == Open ? "Open" : "Close") << '\n';
            } break;
        }
    }
}
