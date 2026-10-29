# HBK Console Calculator

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg?style=flat-square&logo=c%2B%2B)
![CMake](https://img.shields.io/badge/CMake-3.15%2B-064F8C.svg?style=flat-square&logo=cmake)
![Tests](https://img.shields.io/badge/tests-passing-brightgreen.svg?style=flat-square)
![Dependencies](https://img.shields.io/badge/dependencies-0-orange.svg?style=flat-square)

A lightweight console calculator implemented in modern **C++17** that evaluates mathematical expressions respecting standard operator precedence, built with **zero external dependencies**.

---

## Quick Start

### Build
    cmake -B build -S .
    cmake --build build

*(On Windows with MinGW: `cmake -G "MinGW Makefiles" -B build -S .`)*

### Run Calculator
    ./build/calculator

### Run Tests
    ./build/calculator_tests

---

## Example Usage

    > 10-2*6/4
    = 7
    > 2 + 3 * 4.5
    = 15.5
    > 10 / 0
    Error: Division by zero error.
    > exit

---

## Project Structure

```text
.
├── include/
│   ├── token.hpp             # Token definitions and data structures
│   ├── tokenizer.hpp         # Lexical analyzer interface
│   └── calculator.hpp        # Two-pass calculation engine interface
├── source/
│   ├── tokenizer.cpp         # Lexer implementation & grammar validation
│   ├── calculator.cpp        # Operator precedence & evaluation logic
│   └── main.cpp              # Interactive CLI REPL loop
├── tests/
│   └── test_calculator.cpp   # Standalone unit & edge case tests
├── CMakeLists.txt            # Build configuration
├── MANUAL.txt                # Detailed user manual
└── DESIGN.txt                # Software design & verification document
```

---

## Key Features

- **Standard Precedence:** Evaluates `*` and `/` before `+` and `-` using a two-pass folding algorithm (O(N) time complexity).
- **Strict Grammar Validation:** Ensures alternating operands/operators and non-digit boundaries.
- **Zero Third-Party Dependencies:** Uses only standard C++17 library components.
- **Robust Error Handling:** Detects zero division, malformed numbers, and syntax errors.
- **Comprehensive Test Suite:** Unit tests covering basic math, operator precedence, precision, and error diagnostics.

> For detailed technical design and user documentation, refer to `DESIGN.txt` and `MANUAL.txt`.