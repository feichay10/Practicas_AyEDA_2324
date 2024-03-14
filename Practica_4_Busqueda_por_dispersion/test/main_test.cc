#include <iostream>

#include "../include/dfModule.h"
#include "../include/dfRandom.h"
#include "../include/dfSum.h"
#include "../include/dispersionFunction.h"
#include "../include/dynamicSequence.h"
#include "../include/efDoubleDispersion.h"
#include "../include/efLineal.h"
#include "../include/efQuadratic.h"
#include "../include/efRedispersion.h"
#include "../include/explorationFunction.h"
#include "../include/hashTable.h"
#include "../include/nif.h"
#include "../include/sequence.h"
#include "../include/staticSequence.h"
#include "../include/nif.h"

using Key = Nif;

int main() {
  unsigned tableSize = 10;
  dfModule<Key> dfModule(tableSize);
  dfSum<Key> dfSum(tableSize);
  dfRandom<Key> dfRandom(tableSize);
  // Key k = 123445;
  Key k;
  std::cout << "NIF: " << k << std::endl;
  std::cout << "Module: " << dfModule(k) << std::endl;
  std::cout << "Suma: " << dfSum(k) << std::endl;
  std::cout << "Random: " << dfRandom(k) << std::endl;
  
  Key k1 = 78767650;

  std::cout << "NIF: " << k1 << k1.letterNif(k1) << std::endl;

  // Creame 6 NIFs aleatorios y guardalos en un array
  Nif nifs[6];
  for (int i = 0; i < 6; i++) {
    std::cout << "NIF: " << nifs[i] << nifs[i].letterNif(nifs[i]) << std::endl;
  }
}