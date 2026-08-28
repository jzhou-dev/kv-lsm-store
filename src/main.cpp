#include "Engine/Engine.hpp"
#include <iostream>

int main() {
  Engine engine(10, .5);
  std::string request = "";
  for (int i = 0; i < 10; ++i) {
    request.push_back('a' + i);
    engine.Post(request, request);
  }
  engine.print();
  return 0;
}
