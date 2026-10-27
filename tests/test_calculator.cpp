#include "calculator.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

struct TestCase {
    std::string expr;
    double expected;
    bool shouldFail;
};

int main() {
    std::vector<TestCase> cases = {
        {"10-2*6/4", 7.0, false},
        {"5 + 3", 8.0, false},
        {"10 - 4", 6.0, false},
        {"6 * 7", 42.0, false},
        {"15 / 3", 5.0, false},
        {"2 + 3 * 4", 14.0, false},
        {"3 * 4 + 2", 14.0, false},
        {"10 - 2 * 3 + 4 / 2", 6.0, false},
        {"5.5 + 2.25", 7.75, false},
        {"100 / 2 / 2", 25.0, false},
        {"10 / 0", 0.0, true},
        {"+ 5 + 3", 0.0, true},
        {"5 + 3 -", 0.0, true},
        {"5 ++ 3", 0.0, true},
        {"", 0.0, true}
    };

    int passed = 0;
    std::cout << "Running test suite...\n";

    for (const auto& tc : cases) {
        try {
            double res = Calculator::evaluate(tc.expr);
            if (tc.shouldFail) {
                std::cout << "[FAIL] Expected failure for: \"" << tc.expr << "\"\n";
            } else if (std::abs(res - tc.expected) > 1e-6) {
                std::cout << "[FAIL] \"" << tc.expr << "\" expected " << tc.expected << ", got " << res << "\n";
            } else {
                passed++;
            }
        } catch (const std::exception&) {
            if (tc.shouldFail) {
                passed++;
            } else {
                std::cout << "[FAIL] Unexpected exception for \"" << tc.expr << "\"\n";
            }
        }
    }

    std::cout << "Tests completed: " << passed << "/" << cases.size() << " passed.\n";
    return (passed == static_cast<int>(cases.size())) ? 0 : 1;
}