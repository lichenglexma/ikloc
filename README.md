# ikloc

A C++20 project built with CMake.

## Layout

```
include/ikloc/   public headers
src/             library sources and main.cpp
tests/           tests, run with CTest
```

## Build and test

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
./build/ikloc Ada        # prints "Hello, Ada!"
```

Requires CMake 3.20+ and a C++20 compiler (Clang 14+, GCC 11+, or MSVC 2022).

## Tooling

- **clangd**: configuring writes `build/compile_commands.json`, and `.clangd`
  points clangd at it. In Claude Code, install the language server and run
  `/plugin install clangd-lsp@claude-plugins-official`.
- **clang-tidy**: `clang-tidy -p build src/*.cpp tests/*.cpp`
- **clang-format**: `clang-format -i src/*.cpp include/ikloc/*.hpp tests/*.cpp`
