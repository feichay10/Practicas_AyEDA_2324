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

HashTableParameters checkProgramParameters(int argc, char* argv[], HashTableParameters& parameters) {
  if (argc == 2 && std::string(argv[1]) == "-help") {
    throw kUsage;
    exit(EXIT_FAILURE);
  } else if (argc == 1) {
    throw std::string("No arguments provided. Use ") + argv[0] +
        " -help for more information.";
    exit(EXIT_FAILURE);
  }

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
          parameters.dispersionTechnic = std::string(argv[i + 1]);
        }
      } else {
        throw std::string("Dispersion technic not provided.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-bs") {
      if (i + 1 < argc) {
        if (std::stoi(argv[i + 1]) < 1) {
          throw std::string("Invalid block size. Block size must be greater than 0.");
          exit(EXIT_FAILURE);
        } else {
          parameters.blockSize = std::stoi(argv[i + 1]);
        }
      } else {
        throw std::string("Block size not provided.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string (argv[i]) == "-fe") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) != "lineal" && std::string(argv[i + 1]) != "quadratic" && std::string(argv[i + 1]) != "double" && std::string(argv[i + 1]) != "redispersion") {
          throw std::string("Invalid exploration function. Use lineal, quadratic, double or redispersion.");
          exit(EXIT_FAILURE);
        } else {
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

  return parameters;
}

void makeHashTable(HashTableParameters& parameters) {
  DispersionFunction<keyType>* dispersionFunction;
  ExplorationFunction<keyType>* explorationFunction;
  
  if (parameters.df == "module") {
    dispersionFunction = new dfModule<keyType>(parameters.tableSize);
  } else if (parameters.df == "sum") {
    dispersionFunction = new dfSum<keyType>(parameters.tableSize);
  } else if (parameters.df == "random") {
    dispersionFunction = new dfRandom<keyType>(parameters.tableSize);
  }

  if (parameters.dispersionTechnic == "open") {
    std::cout << "\nOpen dispersion" << std::endl;
    HashTable<keyType, DynamicSequence<keyType>> hashTable(parameters.tableSize, *dispersionFunction);
    menu(hashTable);
  } else if (parameters.dispersionTechnic == "close") {
    if (parameters.ef == "lineal") {
      explorationFunction = new efLineal<keyType>;
    } else if (parameters.ef == "double") {
      explorationFunction = new efDoubleDispersion<keyType>;
    } else if (parameters.ef == "quadratic") {
      explorationFunction = new efQuadratic<keyType>;
    } else if (parameters.ef == "redispersion") {
      explorationFunction = new efRedispersion<keyType>;
    }
    std::cout << "\nClose dispersion" << std::endl;
    HashTable<keyType, StaticSequence<keyType>> hashTable(parameters.tableSize, *dispersionFunction, *explorationFunction, parameters.blockSize);
    menu(hashTable);
  }
}

template <typename HashTableType>
void menu(HashTableType& hashTable) {
  // Comprobar el tipo de hashTable
  // std::cout << typeid(hashTable).name() << std::endl;

  std::string option;
  int optionMenu;
  while (true) {
    std::cout << "\n###### Tabla de Hash ######" << std::endl;
    std::cout << kRedBold << "  [1]." << kReset << kBold << " Insertar" << std::endl;
    std::cout << kRedBold << "  [2]." << kReset << kBold << " Buscar" << std::endl;
    std::cout << kRedBold << "  [3]." << kReset << kBold << " Imprimir tabla" << std::endl;
    std::cout << kRedBold << "  [4]." << kReset << kBold << " Salir" << kReset << std::endl;
    std::cout << "Selecciona una opción: ";
    std::cin >> option;

    // Si la opción es de tipo char, muestra un mensaje de opción no válida
    if (option.size() == 1 && isalpha(option[0])) {
      std::cout << kRedBold << "Opción no válida" << kReset << std::endl;
      continue;
    } 

    // Si la opción es un número, la convierte a entero
    if (isalnum(option[0]) && option.size() == 1) {
      optionMenu = std::stoi(option);
    } else {
      std::cout << kRedBold << "Opción no válida" << kReset << std::endl;
      continue;
    }

    // Si la opcion es una string que no es un número, muestra un mensaje de opción no válida
    if (option.size() > 1) {
      std::cout << kRedBold << "Opción no válida" << kReset << std::endl;
      continue;
    }

    // system("clear");

    switch (optionMenu) {
      case 1: {
        keyType key;
        std::cout << kBold << "Introduce la clave a insertar: " << kReset;
        std::cin >> key;
        hashTable.insert(key);
        hashTable.print();
        break;
      }
      case 2: {
        keyType key;
        std::cout << kBold << "Introduce la clave a buscar: " << kReset;
        std::cin >> key;
        if (!hashTable.search(key)) {
          std::cout << "La clave " << kCyanBold << key << kReset << kRedBold << " NO" << kReset << " no se encuentra en la tabla" << kReset << std::endl << std::endl;
        } else {
          std::cout << "La clave " << kCyanBold << key << kReset << kGreenBold << " SI" << kReset << " se encuentra en la tabla" << kReset << std::endl << std::endl;
        }
        break;
      }
      case 3:
        std::cout << kBold << "Tabla hash: " << kReset << std::endl;
        hashTable.print();
        break;
      case 4:
        std::cout << kBold << "Saliendo..." << kReset << std::endl;
        exit(EXIT_SUCCESS);
      default:
        std::cout << kRedBold << "Opción no válida" << kReset << std::endl;
        break;
    }
  }
}