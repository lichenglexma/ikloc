cmake_minimum_required(VERSION 3.20)

project(ikloc
  VERSION 0.1.0
  DESCRIPTION "ikloc"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Writes build/compile_commands.json for clangd and clang-tidy.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Warnings applied to every target in this project.
add_library(ikloc_warnings INTERFACE)
if(MSVC)
  target_compile_options(ikloc_warnings INTERFACE /W4 /permissive-)
else()
  target_compile_options(ikloc_warnings INTERFACE
    -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion)
endif()

# Core library: put the real code here so tests can link it.
add_library(ikloc_lib
  src/ikloc.cpp)
target_include_directories(ikloc_lib PUBLIC include)
target_link_libraries(ikloc_lib PRIVATE ikloc_warnings)

# Executable
add_executable(ikloc src/main.cpp)
target_link_libraries(ikloc PRIVATE ikloc_lib ikloc_warnings)

# Tests
include(CTest)
if(BUILD_TESTING)
  add_executable(ikloc_tests tests/test_ikloc.cpp)
  target_link_libraries(ikloc_tests PRIVATE ikloc_lib ikloc_warnings)
  add_test(NAME ikloc_tests COMMAND ikloc_tests)
endif()
