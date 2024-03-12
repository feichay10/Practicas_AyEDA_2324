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
  } else if (df == "sum") {
    dispersionFunction = new dfSum<keyType>(tableSize);
  } else if (df == "random") {
    dispersionFunction = new dfRandom<keyType>(tableSize);
  }

  if (dispersionTechnic == "open") {
    HashTable<keyType, DynamicSequence<keyType>> hashTable(tableSize, *dispersionFunction);
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
    HashTable<keyType, StaticSequence<keyType>> hashTable(tableSize, *dispersionFunction, *explorationFunction, blockSize);
  }

  // delete dispersionFunction;
  // delete explorationFunction;
}

void menuOpen(HashTable<keyType, DynamicSequence<keyType>> hashTable) {
  int option = 0;
  do {
    std::cout << kGreenBold << "1. Insertar" << kReset << std::endl;
    std::cout << kGreenBold << "2. Buscar" << kReset << std::endl;
    std::cout << kGreenBold << "3. Salir" << kReset << std::endl;
    std::cout << kBold << "Opción: " << kReset;
    std::cin >> option;
    
    switch (option) {
      case 1: {
        keyType key;
        std::cout << kBold << "Introduce la clave a insertar: " << kReset;
        std::cin >> key;
        hashTable.insert(key);
        break;
      }
      case 2: {
        keyType key;
        std::cout << kBold << "Introduce la clave a buscar: " << kReset;
        std::cin >> key;
        if (hashTable.search(key)) {
          std::cout << kGreenBold << "Clave encontrada" << kReset << std::endl;
        } else {
          std::cout << kRedBold << "Clave no encontrada" << kReset << std::endl;
        }
        break;
      }
      case 3:
        std::cout << kBold << "Saliendo..." << kReset << std::endl;
        exit(EXIT_SUCCESS);
      default:
        std::cout << kRedBold << "Opción no válida" << kReset << std::endl;
        break;
    }
  } while (option != 3);
}