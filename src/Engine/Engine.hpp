#pragma once

#include "ResponseStatus.hpp"
#include <string_view>

class Engine {
  ResponseStatus Get(std::string_view key);
  ResponseStatus Post(std::string_view key, std::string_view value);
  ResponseStatus Put(std::string_view key, std::string_view value);
  ResponseStatus Delete(std::string_view key);
};
