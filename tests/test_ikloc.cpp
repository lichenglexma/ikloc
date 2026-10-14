// Minimal dependency-free tests. Swap in GoogleTest or Catch2 when the
// project grows.
#include <iostream>
#include <string>

#include "ikloc/ikloc.hpp"

namespace {

int failures = 0;

void expect_eq(const std::string& actual, const std::string& expected,
               const char* what) {
  if (actual != expected) {
    std::cerr << "FAIL " << what << ": expected \"" << expected
              << "\", got \"" << actual << "\"\n";
    ++failures;
  }
}

}  // namespace

int main() {
  expect_eq(ikloc::greet("Ada"), "Hello, Ada!", "greet with name");
  expect_eq(ikloc::greet(""), "Hello, world!", "greet with empty name");
  expect_eq(std::string{ikloc::version()}, "0.1.0", "version");

  if (failures == 0) {
    std::cout << "All tests passed\n";
  }
  return failures == 0 ? 0 : 1;
}
