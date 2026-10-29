#include "tokenizer.hpp"
#include <cctype>
#include <stdexcept>

std::vector<Token> Tokenizer::tokenize(const std::string& input) {
    std::vector<Token> tokens;
    tokens.reserve(input.length() / 2 + 1);

    size_t i = 0;
    const size_t n = input.length();

    while (i < n) {
        char c = input[i];

        if (std::isspace(static_cast<unsigned char>(c))) {
            ++i;
            continue;
        }

        // Liczba musi zaczynać się od cyfry, lub od kropki po której zaraz jest cyfra (np. .5)
        bool isNumberStart = std::isdigit(static_cast<unsigned char>(c)) || 
                             (c == '.' && (i + 1 < n) && std::isdigit(static_cast<unsigned char>(input[i + 1])));

        if (isNumberStart) {
            size_t nextIdx = 0;
            std::string sub = input.substr(i);
            try {
                double val = std::stod(sub, &nextIdx);
                tokens.push_back({TokenType::Number, val});
                i += nextIdx;
            } catch (...) {
                throw std::runtime_error("Malformed number encountered at index " + std::to_string(i));
            }
            continue;
        }

        switch (c) {
            case '+': tokens.push_back({TokenType::Add, 0.0}); break;
            case '-': tokens.push_back({TokenType::Subtract, 0.0}); break;
            case '*': tokens.push_back({TokenType::Multiply, 0.0}); break;
            case '/': tokens.push_back({TokenType::Divide, 0.0}); break;
            default:
                throw std::runtime_error(std::string("Unrecognized character: '") + c + "'");
        }
        ++i;
    }

    validateGrammar(tokens);
    return tokens;
}

void Tokenizer::validateGrammar(const std::vector<Token>& tokens) {
    if (tokens.empty()) {
        throw std::runtime_error("Expression is empty.");
    }

    if (tokens.front().type != TokenType::Number) {
        throw std::runtime_error("Expression must start with a number.");
    }
    if (tokens.back().type != TokenType::Number) {
        throw std::runtime_error("Expression must end with a number.");
    }

    for (size_t i = 0; i < tokens.size() - 1; ++i) {
        bool isCurrentNum = (tokens[i].type == TokenType::Number);
        bool isNextNum = (tokens[i + 1].type == TokenType::Number);

        if (isCurrentNum && isNextNum) {
            throw std::runtime_error("Consecutive operands without operator.");
        }
        if (!isCurrentNum && !isNextNum) {
            throw std::runtime_error("Consecutive operators detected.");
        }
    }
}