#pragma once

enum class TokenType {
    Number,
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Token {
    TokenType type;
    double value{0.0};
};