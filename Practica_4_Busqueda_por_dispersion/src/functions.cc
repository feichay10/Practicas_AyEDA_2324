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

void makeHashTable(unsigned tableSize, std::string df, std::string dispersionTechnic, unsigned blockSize, std::string ef) {
  DispersionFunction<keyType>* dispersionFunction;
  ExplorationFunction<keyType>* explorationFunction;

  if (df == "module") {
    dispersionFunction = new dfModule<keyType>(tableSize); 
  } else if (df == "random") {
    dispersionFunction = new dfRandom<keyType>(tableSize);
  } else if (df == "sum") {
    dispersionFunction = new dfSum<keyType>(tableSize);
  }

  if (dispersionTechnic == "open") {
    HashTable<keyType, DynamicSequence<keyType>>* hashTable = new HashTable<keyType, DynamicSequence<keyType>>(tableSize, *dispersionFunction);
  } else if (dispersionTechnic == "close") {
    if (ef == "lineal") {
      explorationFunction = new efLineal<keyType>;
    } else if (ef == "double") {
      explorationFunction = new efDoubleDispersion<keyType>;
    } else if (ef == "quadratic") {
      explorationFunction = new efQuadratic<keyType>;
    } else if (ef == "redispersion") {
      explorationFunction = new efRedispersion<keyType>;
    }
    // hashTable = new HashTable<keyType, Sequence<keyType>>(tableSize, *dispersionFunction, *explorationFunction, blockSize);
  }
}