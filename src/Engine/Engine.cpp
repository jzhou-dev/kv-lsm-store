#include "Engine.hpp"

ResponseStatus Engine::Get(const std::string &key) { return list.search(key); }

ResponseStatus Engine::Post(const std::string &key, const std::string &value) {
  return list.insert(key, value);
}
