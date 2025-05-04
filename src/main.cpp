#include "../include/scanner.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    auto [tokens, scanner_log, errors, lines] = scan("main.sc");
    for (std::array<string, 2> line : scanner_log) {
        cout << line[0] << '\n' << line[1] << "\n\n";
    }
    cout << "\nNumber of Tokens: " << tokens.size() << '\n';
    cout << "Number of lines: " << lines << '\n';
    cout << "Number of errors: " << errors << '\n';
}
