#include "ikloc/ikloc.hpp"

namespace ikloc {

std::string_view version() noexcept { return "0.1.0"; }

std::string greet(std::string_view name) {
  std::string result = "Hello, ";
  result += name.empty() ? std::string_view{"world"} : name;
  result += '!';
  return result;
}

}  // namespace ikloc
