#include "../include/scanner.hpp"
#include <vector>

using namespace std;

int main() {
    string identifier;
    cin >> identifier;
    T_identifier id = new T_identifier_(identifier);
    cout << id->getIdentifier() << " is " << (id->isValid() ? "" : "not ")
         << "a valid identifier";
}
