#include "../include/scanner.hpp"
#include <vector>

using namespace std;

int main() {
    vector<Token *> tokens;

    T_SInteger *sint = new T_SInteger(54, negative);
    T_Character *charac = new T_Character('a');

    tokens.push_back(sint);
    tokens.push_back(charac);

    for (Token *token : tokens) {
        if (token->getTokenType() == Variable) {
            T_var *var = dynamic_cast<T_var *>(token);
            cout << "ID: " << var->getID() << endl;
            if (var->getDataType() == SInteger) {
                T_SInteger *sinteger = dynamic_cast<T_SInteger *>(var);
                cout << "Type: signed integer\n";
                cout << "Value: " << sinteger->getValue() << endl;
                cout << "Sign: "
                     << (sinteger->getSign() == positive ? '+' : '-') << endl;
                cout << endl;
            } else if (var->getDataType() == Character) {
                T_Character *character = dynamic_cast<T_Character *>(var);
                cout << "Type: character\n";
                cout << "Chracter: " << character->getValue() << endl;
                cout << endl;
            }
        }
    }
}
