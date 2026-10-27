#include "Calculator.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::cout << "========================================\n";
    std::cout << "          HBK Console Calculator        \n";
    std::cout << "========================================\n";
    std::cout << "Type expression (e.g. 10-2*6/4) and press Enter.\n";
    std::cout << "Type 'exit' or 'quit' to terminate.\n\n";

    std::string line;
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) {
            break;
        }

        if (line == "exit" || line == "quit") {
            break;
        }

        if (line.empty()) {
            continue;
        }

        try {
            double result = Calculator::evaluate(line);
            std::cout << "= " << std::setprecision(10) << result << "\n";
        } catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << "\n";
        }
    }

    return 0;
}