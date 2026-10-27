#pragma once

#include "Token.hpp"
#include <string>
#include <vector>

class Tokenizer {
public:
    static std::vector<Token> tokenize(const std::string& input);

private:
    static void validateGrammar(const std::vector<Token>& tokens);
};