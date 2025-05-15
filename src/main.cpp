#include "../include/scanner.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    auto [tokens, errors, lines] = scan("main.sc");
    for (Token token : tokens) {
        array<string, 2> token_info = tokenInfo(token);
        cout << token_info[0] << '\n' << token_info[1] << "\n\n";
    }
    cout << "\nNumber of Tokens: " << tokens.size() << '\n';
    cout << "Number of lines: " << lines << '\n';
    cout << "Number of errors: " << errors << '\n';
}
