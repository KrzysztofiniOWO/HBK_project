#pragma once

#include "Token.hpp"
#include <string>
#include <vector>

class Calculator {
public:
    static double evaluate(const std::string& expression);

private:
    static double evaluateTokens(const std::vector<Token>& tokens);
};