cmake_minimum_required(VERSION 3.15)
project(HBKCalculator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Rygorystyczne flagi kompilatora
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Biblioteka rdzenia (logika biznesowa)
add_library(calculator_core STATIC
    source/tokenizer.cpp
    source/calculator.cpp
)
target_include_directories(calculator_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Aplikacja konsolowa CLI
add_executable(calculator source/main.cpp)
target_link_libraries(calculator PRIVATE calculator_core)

# Zestaw testów jednostkowych
enable_testing()
add_executable(calculator_tests tests/test_calculator.cpp)
target_link_libraries(calculator_tests PRIVATE calculator_core)
add_test(NAME AllCalculatorTests COMMAND calculator_tests)