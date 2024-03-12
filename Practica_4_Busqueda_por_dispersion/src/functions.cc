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

void checkProgramParameters(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "-help") {
    throw kUsage;
    exit(EXIT_FAILURE);
  } else if (argc == 1) {
    throw std::string("No arguments provided. Use ") + argv[0] +
        " -help for more information.";
    exit(EXIT_FAILURE);
  }

  HashTableParameters parameters;

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-ts") {
      if (i + 1 < argc) {
        if (std::stoi(argv[i + 1]) < 1) {
          throw std::string("Invalid table size. Table size must be greater than 0.");
          exit(EXIT_FAILURE);
        } else {
          parameters.tableSize = std::stoi(argv[i + 1]);
        }
      } else {
        throw std::string("Table size not provided.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-fd") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) != "module" && std::string(argv[i + 1]) != "sum" && std::string(argv[i + 1]) != "random") {
          throw std::string("Invalid dispersion function. Use random or sum.");
          exit(EXIT_FAILURE);
        } else {
          // df = std::string(argv[i + 1]);
          parameters.df = std::string(argv[i + 1]);
        }
      } else {
        throw std::string("Dispersion function not provided.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-hash") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) != "open" && std::string(argv[i + 1]) != "close") {
          throw std::string("Invalid dispersion technic. Use open or closed.");
          exit(EXIT_FAILURE);
        } else {
          // dispersionTechnic = std::string(argv[i + 1]);
          parameters.dispersionTechnic = std::string(argv[i + 1]);
        }
      } else {
        throw std::string("Dispersion technic not provided.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string (argv[i]) == "-fe") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) != "lineal" && std::string(argv[i + 1]) != "quadratic" && std::string(argv[i + 1]) != "double" && std::string(argv[i + 1]) != "redispersion") {
          throw std::string("Invalid exploration function. Use lineal, quadratic, double or redispersion.");
          exit(EXIT_FAILURE);
        } else {
          // ef = std::string(argv[i + 1]);
          parameters.ef = std::string(argv[i + 1]);
        }
      } else {
        throw std::string("Exploration function not provided.");
        exit(EXIT_FAILURE);
      }
    }
  }

  std::cout << "Table size: " << parameters.tableSize << std::endl;
  std::cout << "Dispersion function: " << parameters.df << std::endl;
  std::cout << "Dispersion technic: " << parameters.dispersionTechnic << std::endl;
  std::cout << "Block size: " << parameters.blockSize << std::endl;
  std::cout << "Exploration function: " << parameters.ef << std::endl;
}

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
    menu(static_cast<HashTable<keyType, DynamicSequence<keyType>>>(hashTable));
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


void menu(HashTable<keyType, DynamicSequence<keyType>> hashTable) {
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
