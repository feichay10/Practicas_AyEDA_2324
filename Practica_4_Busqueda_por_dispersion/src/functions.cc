/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/functions.h"

void makeHashTable(int tableSize, std::string df, std::string dispersionTechnic, int blockSize, std::string ef) {
  DispersionFunction<keyType>* dispersionFunction;
  ExplorationFunction<keyType>* explorationFunction;
  Sequence<keyType>* sequence;

  if (df == "module") {
    dispersionFunction = new dfModule<keyType>(tableSize);
  } else if (df == "random") {
    dispersionFunction = new dfRandom<keyType>(tableSize);
  } else if (df == "sum") {
    dispersionFunction = new dfSum<keyType>(tableSize);
  }

  if (dispersionTechnic == "open") {
    sequence = new DynamicSequence<keyType>();
    // HashTable<keyType, DynamicSequence<keyType>> hashTable(tableSize, *dispersionFunction, *explorationFunction, blockSize);
  } else if (dispersionTechnic == "close") {
    sequence = new StaticSequence<keyType>(blockSize);
  }
}