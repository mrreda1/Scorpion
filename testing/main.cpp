#include "../include/scanner.hpp"
#include <vector>

using namespace std;

int main() {
    vector<T_var> variables;
    T_Character var_c = new T_Character_("c", 'a');
    T_Integer var_x = new T_Integer_("x", 4543);
    T_Integer var_y = new T_Integer_("y");
    Token token = new Token_(Condition);

    variables.push_back(var_c);
    variables.push_back(var_x);
    variables.push_back(var_y);

    for (T_var var : variables) {
        cout << "\nID: " << var->getID() << '\n';
        switch (var->getDataType()) {
            case D_Character: {
                T_Character char_var = dynamic_cast<T_Character>(var);
                cout << "Type: Character\n";
                cout << "Char: " << char_var->getValue() << '\n';
            } break;
            case D_Integer: {
                T_Integer int_var = dynamic_cast<T_Integer>(var);
                cout << "Type: Integer\n";
                cout << "Value: " << int_var->getValue() << '\n';
            } break;
        }
    }

    cout << T_var_::getVariable(0)->getName() << '\n';
    cout << T_var_::getVariable("y")->getID() << '\n';
}