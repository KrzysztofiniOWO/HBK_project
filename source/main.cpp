#include "calculator.hpp"
#include <iostream>

int main() {
    try {
        std::string expr = "10-2*6/4";
        double result = Calculator::evaluate(expr);
        std::cout << "Expression: " << expr << "\n";
        std::cout << "Result: " << result << " (Expected: 7)\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}