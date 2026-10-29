#include "calculator.hpp"
#include "tokenizer.hpp"
#include <cmath>
#include <limits>
#include <stdexcept>

double Calculator::evaluate(const std::string& expression) {
    std::vector<Token> tokens = Tokenizer::tokenize(expression);
    return evaluateTokens(tokens);
}

double Calculator::evaluateTokens(const std::vector<Token>& tokens) {
    std::vector<Token> pass1;
    size_t i = 0;

    while (i < tokens.size()) {
        if (tokens[i].type == TokenType::Multiply || tokens[i].type == TokenType::Divide) {
            if (pass1.empty() || i + 1 >= tokens.size() || tokens[i + 1].type != TokenType::Number) {
                throw std::runtime_error("Evaluation syntax error around operator.");
            }

            double left = pass1.back().value;
            pass1.pop_back();
            double right = tokens[i + 1].value;

            if (tokens[i].type == TokenType::Multiply) {
                pass1.push_back({TokenType::Number, left * right});
            } else {
                if (std::abs(right) < std::numeric_limits<double>::epsilon()) {
                    throw std::runtime_error("Division by zero error.");
                }
                pass1.push_back({TokenType::Number, left / right});
            }
            i += 2;
        } else {
            pass1.push_back(tokens[i]);
            ++i;
        }
    }

    if (pass1.empty() || pass1[0].type != TokenType::Number) {
        throw std::runtime_error("Unexpected state in additive phase.");
    }

    double result = pass1[0].value;
    for (size_t j = 1; j < pass1.size(); j += 2) {
        TokenType op = pass1[j].type;
        double right = pass1[j + 1].value;

        if (op == TokenType::Add) {
            result += right;
        } else if (op == TokenType::Subtract) {
            result -= right;
        } else {
            throw std::runtime_error("Invalid operator in additive phase.");
        }
    }

    return result;
}