#include "calculator.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>

struct TestCase {
    std::string name;
    std::string expr;
    double expected;
    bool shouldFail;
};

int main() {
    const std::vector<TestCase> testCases = {
        // --- Spec Requirement & Basic Arithmetic ---
        {"Spec Example", "10-2*6/4", 7.0, false},
        {"Simple Addition", "5 + 3", 8.0, false},
        {"Simple Subtraction", "10 - 4", 6.0, false},
        {"Simple Multiplication", "6 * 7", 42.0, false},
        {"Simple Division", "15 / 3", 5.0, false},

        // --- Precedence & Associativity ---
        {"Add then Multiply", "2 + 3 * 4", 14.0, false},
        {"Multiply then Add", "3 * 4 + 2", 14.0, false},
        {"Mixed Precedence", "10 - 2 * 3 + 4 / 2", 6.0, false},
        {"Left-to-Right Division", "100 / 2 / 2", 25.0, false},
        {"Left-to-Right Subtraction", "10 - 3 - 2", 5.0, false},
        {"Chained Additions", "1 + 2 + 3 + 4 + 5", 15.0, false},

        // --- Decimals & Precision ---
        {"Decimal Addition", "5.5 + 2.25", 7.75, false},
        {"Decimal Division", "10 / 4", 2.5, false},
        {"Fraction Cancellation", "1 / 3 * 3", 1.0, false},

        // --- Single Operand & Zero Handling ---
        {"Single Integer", "42", 42.0, false},
        {"Single Decimal", "3.1415", 3.1415, false},
        {"Zero Addition", "0 + 0", 0.0, false},
        {"Zero Numerator", "0 / 5", 0.0, false},

        // --- Whitespace Variations ---
        {"Dense (No Spaces)", "3+4*2-1", 10.0, false},
        {"Heavy Whitespace", "  10   -   2  *  6  /  4  ", 7.0, false},
        {"Tab and Newline", "5\t+\n3", 8.0, false},

        // --- Expected Failure Cases ---
        {"Division by Int Zero", "10 / 0", 0.0, true},
        {"Division by Float Zero", "10 / 0.0", 0.0, true},
        {"Empty String", "", 0.0, true},
        {"Whitespace Only", "   ", 0.0, true},
        {"Leading Operator", "+ 5 + 3", 0.0, true},
        {"Trailing Operator", "5 + 3 -", 0.0, true},
        {"Consecutive Operators", "5 ++ 3", 0.0, true},
        {"Operator Collision", "10 * / 2", 0.0, true},
        {"Consecutive Operands", "5 3 + 2", 0.0, true},
        {"Unsupported Parentheses", "(2 + 3) * 4", 0.0, true},
        {"Invalid Alpha Characters", "2 + abc * 3", 0.0, true},
        {"Multiple Decimal Points", "1.2.3 + 4", 0.0, true}
    };

    int passed = 0;
    std::cout << "========================================\n";
    std::cout << "         HBK Calculator Test Suite      \n";
    std::cout << "========================================\n";

    for (const auto& tc : testCases) {
        try {
            double res = Calculator::evaluate(tc.expr);
            if (tc.shouldFail) {
                std::cout << "[FAIL] " << tc.name << ": Expected error for \"" << tc.expr 
                          << "\", but got " << res << "\n";
            } else if (std::abs(res - tc.expected) > 1e-6) {
                std::cout << "[FAIL] " << tc.name << ": \"" << tc.expr << "\" expected " 
                          << tc.expected << ", got " << res << "\n";
            } else {
                std::cout << "[PASS] " << tc.name << "\n";
                passed++;
            }
        } catch (const std::exception& e) {
            if (tc.shouldFail) {
                std::cout << "[PASS] " << tc.name << " (Caught expected error: " << e.what() << ")\n";
                passed++;
            } else {
                std::cout << "[FAIL] " << tc.name << ": Unexpected exception for \"" 
                          << tc.expr << "\": " << e.what() << "\n";
            }
        }
    }

    std::cout << "\nResult: " << passed << "/" << testCases.size() << " tests passed.\n";
    return (passed == static_cast<int>(testCases.size())) ? 0 : 1;
}