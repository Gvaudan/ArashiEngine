#include <iostream>
#include <boost/log/core.hpp>

#include "GameContext.hh"

int main() {
  std::cout << "Hello, World!" << std::endl;

  Context::Context::get_instance()->initialize();
  Context::Context::get_instance()->run();

  return 0;
}