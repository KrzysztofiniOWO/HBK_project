cmake_minimum_required(VERSION 3.15)
project(HBKCalculator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_library(calculator_core STATIC
    src/Tokenizer.cpp
)
target_include_directories(calculator_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(calculator src/main.cpp)
target_link_libraries(calculator PRIVATE calculator_core)