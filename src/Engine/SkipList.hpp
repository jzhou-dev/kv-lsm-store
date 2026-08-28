#pragma once

#include "ResponseStatus.hpp"
#include <string>
#include <vector>

struct Node {
  std::string key;
  std::string value;
  bool tombstone;
  std::vector<Node *> forward;

  Node(const std::string &k, const std::string &v, int height)
      : key(k), value(v), tombstone(false), forward(height, nullptr) {};
};

class SkipList {
public:
  SkipList(int _max_level, float _p);
  ResponseStatus insert(const std::string &key, const std::string &value);
  ResponseStatus get(const std::string &key) const;
  ResponseStatus update(const std::string &key, const std::string &value);
  ResponseStatus remove(const std::string &key);

private:
  int max_level;
  float p;        // probability of moving to next level
  int curr_level; // highest level currently in use
  Node *head;

  int randomLevel();
};
