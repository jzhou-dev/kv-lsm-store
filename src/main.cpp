#include "Engine/Engine.hpp"
#include <iostream>

int main() {
  Engine engine(10, .5);
  std::cout << ToString(engine.Post("Hello", "World")) << std::endl;
  std::cout << ToString(engine.Post("Goodbye", "World")) << std::endl;
  std::cout << ToString(engine.Get("Ni Hao")) << std::endl;
  std::cout << ToString(engine.Get("Hello")) << std::endl;
  return 0;
}
