#pragma once

#include <string>
#include <string_view>

namespace ikloc {

// Library version, e.g. "0.1.0".
std::string_view version() noexcept;

// Returns a greeting for `name`, or for "world" when `name` is empty.
std::string greet(std::string_view name);

}  // namespace ikloc
