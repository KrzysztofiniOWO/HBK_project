#pragma once

#include "Token.hpp"
#include <string>
#include <vector>

class Calculator {
public:
    /**
     * @brief Parses and evaluates a mathematical expression respecting operator precedence.
     * @param expression Mathematical expression in "<number> <op> <number>" format.
     * @return Calculated numerical result.
     * @throws std::runtime_error On invalid syntax or division by zero.
     */
    static double evaluate(const std::string& expression);

private:
    /**
     * @brief Performs two-pass evaluation (multiplicative fold followed by additive fold).
     * @param tokens Validated token stream.
     * @return Final evaluated result.
     * @throws std::runtime_error On division by zero or evaluation failure.
     */
    static double evaluateTokens(const std::vector<Token>& tokens);
};