#pragma once

#include "response_status.hpp"
#include <string>
#include <vector>

struct Node {
  std::string key;
  std::string value;
  bool tombstone;
  int level;
  Node *below;
  Node *next;
  Node()
      : key(""), value(""), tombstone(false), level(0), below(nullptr),
        next(nullptr) {};
  Node(const std::string &k, const std::string &v)
      : key(k), value(v), tombstone(false), level(0), below(nullptr),
        next(nullptr) {};
  Node(const std::string &k, const std::string &v, int _level)
      : key(k), value(v), tombstone(false), level(_level), below(nullptr),
        next(nullptr) {};
};

class SkipList {
public:
  SkipList();
  SkipList(int _max_level, float _p);
  ResponseStatus search(const std::string &key) const;
  ResponseStatus search(const std::string &key,
                        std::vector<Node *> &prevs) const;
  ResponseStatus insert(const std::string &key, const std::string &value);
  ResponseStatus update(const std::string &key, const std::string &value);
  ResponseStatus remove(const std::string &key);
  void print();

private:
  std::vector<Node *> levels;
  int max_level;
  int curr_level; // highest level currently in use
  float p;        // probability of moving to next level

  int randomLevel();
};
