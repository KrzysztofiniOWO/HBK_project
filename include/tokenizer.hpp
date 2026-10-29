#pragma once

#include "token.hpp"
#include <string>
#include <vector>

class Tokenizer {
public:
    /**
     * @brief Tokenizes an expression string and validates its grammar.
     * @param input Mathematical expression as raw text.
     * @return Sequence of parsed tokens.
     * @throws std::runtime_error On unknown characters, invalid numbers, or malformed syntax.
     */
    static std::vector<Token> tokenize(const std::string& input);

private:
    /**
     * @brief Enforces expression grammar rules (alternating operands and operators).
     * @param tokens Token stream to inspect.
     * @throws std::runtime_error If the expression grammar is invalid.
     */
    static void validateGrammar(const std::vector<Token>& tokens);
};