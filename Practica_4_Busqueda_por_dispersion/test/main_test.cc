#include <iostream>

#include "../include/functions.h"
#include "../include/nif.h"

using Key = Nif;

int main() {
  unsigned tableSize = 10;
  dfModule<Key> dfModule(tableSize);
  dfSum<Key> dfSum(tableSize);
  dfRandom<Key> dfRandom(tableSize);
  Key k = 78767650;
  std::cout << "Module: " << dfModule(k) << std::endl;
  std::cout << "Suma: " << dfSum(k) << std::endl;
  std::cout << "Random: " << dfRandom(k) << std::endl;
}