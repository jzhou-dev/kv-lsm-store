#pragma once

#include "ResponseStatus.hpp"
#include "SkipList.hpp"
#include <string>

class Engine {
public:
  Engine(int _max_level, float _p) : list(_max_level, _p) {};
  ResponseStatus Get(const std::string &key);
  ResponseStatus Post(const std::string &key, const std::string &value);
  ResponseStatus Put(const std::string &key, const std::string &value);
  ResponseStatus Delete(const std::string &key);

private:
  SkipList list;
};
