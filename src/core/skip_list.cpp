#include "SkipList.hpp"
#include <iostream>
#include <random>

SkipList::SkipList() { SkipList(0, 0); }
SkipList::SkipList(int _max_level, float _p) {
  levels = std::vector<Node *>(_max_level, nullptr);
  max_level = _max_level;
  curr_level = 0;
  p = _p;
  for (int i = 0; i < max_level; ++i) {
    levels[i] = new Node("", "", i);
    if (i >= 1) {
      levels[i]->below = levels[i - 1];
    }
  }
}

int SkipList::randomLevel() {
  static std::mt19937 gen(std::random_device{}());
  static std::uniform_int_distribution<int> distrib(1, 100);
  int level = 1;
  int prob = p * 100;
  while (level < max_level && distrib(gen) <= prob) {
    level++;
  }
  return level;
}

void SkipList::print() {
  for (int i = curr_level; i >= 0; --i) {
    Node *curr = levels[i]->next;
    std::cout << "Level " << i << ": ";
    while (curr) {
      std::cout << curr->key;
      if (curr->next) {
        std::cout << " -> ";
      }
      curr = curr->next;
    }
    std::cout << '\n';
  }
}

ResponseStatus SkipList::search(const std::string &key) const {
  std::vector<Node *> temp;
  return search(key, temp);
}

ResponseStatus SkipList::search(const std::string &key,
                                std::vector<Node *> &prevs) const {
  Node *head = levels[curr_level];
  bool found = false;
  while (head) {
    while (head->next && head->next->key < key) {
      head = head->next;
    }
    if (head->level < prevs.size()) {
      prevs[head->level] = head;
    }
    if (head->next && head->next->key == key && !head->next->tombstone) {
      found = true;
    }
    head = head->below;
  }
  if (found) {
    return ResponseStatus::Success;
  }
  return ResponseStatus::NotFoundError;
}

ResponseStatus SkipList::insert(const std::string &key,
                                const std::string &value) {
  std::vector<Node *> prevs(max_level, nullptr);
  for (int i = 0; i < levels.size(); ++i) {
    prevs[i] = levels[i];
  }
  if (search(key, prevs) == ResponseStatus::Success) {
    return ResponseStatus::ServerError;
  };
  int insert_level = randomLevel();
  curr_level = std::max(insert_level, curr_level);
  Node *below_node = nullptr;
  for (int i = 0; i <= insert_level; ++i) {
    Node *new_node = new Node(key, value, i);
    new_node->next = prevs[i]->next;
    prevs[i]->next = new_node;
    new_node->below = below_node;
    below_node = new_node;
  }
  return ResponseStatus::Success;
}

ResponseStatus SkipList::update(const std::string &key,
                                const std::string &value) {}

ResponseStatus SkipList::remove(const std::string &key) {}
