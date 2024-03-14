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
 * @briexplorationFunction
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
    throw std::string("No arguments provided. Use ") + argv[0] + " -help for more information.";
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
          parameters.dispersionFunction = std::string(argv[i + 1]);
        }
      }
    } else if (std::string(argv[i]) == "-hash") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) != "open" && std::string(argv[i + 1]) != "close") {
          throw std::string("Invalid dispersion technic. Use open or closed.");
          exit(EXIT_FAILURE);
        } else {
          parameters.dispersionTechnic = std::string(argv[i + 1]);
        }
      }
    } else if (std::string(argv[i]) == "-bs") {
      if (i + 1 < argc) {
        if (std::stoi(argv[i + 1]) < 1) {
          throw std::string("Invalid block size. Block size must be greater than 0.");
          exit(EXIT_FAILURE);
        } else {
          if (std::stoi(argv[i + 1]) > parameters.tableSize) {
            throw std::string("Invalid block size. Block size must be less than the table size.");
            exit(EXIT_FAILURE);
          } else {
            parameters.blockSize = std::stoi(argv[i + 1]);
          }
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
          parameters.explorationFunction = std::string(argv[i + 1]);
        }
      }
    }
  }

  if (parameters.dispersionTechnic == "open" && parameters.blockSize != 0) {
    throw std::string("Block size is only for close dispersion.");
    exit(EXIT_FAILURE);
  } else if (parameters.dispersionTechnic == "open" && parameters.explorationFunction != "") {
    throw std::string("Exploration function is only for close dispersion.");
    exit(EXIT_FAILURE);
  }

  // Set default values
  if (parameters.dispersionFunction == "") {
    parameters.dispersionFunction = "module";
  } else if (parameters.dispersionTechnic == "") {
    parameters.dispersionTechnic = "open";
  } else if (parameters.explorationFunction == "") {
    parameters.explorationFunction = "lineal";
  }

  std::cout << "Table size: " << parameters.tableSize << std::endl;
  std::cout << "Dispersion function: " << parameters.dispersionFunction << std::endl;
  std::cout << "Dispersion technic: " << parameters.dispersionTechnic << std::endl;
  if (parameters.dispersionTechnic == "close") {
    std::cout << "Block size: " << parameters.blockSize << std::endl;
    std::cout << "Exploration function: " << parameters.explorationFunction << std::endl;
  }

  return parameters;
}

void makeHashTable(HashTableParameters& parameters) {
  DispersionFunction<keyType>* dispersionFunction;
  ExplorationFunction<keyType>* explorationFunction;
  
  if (parameters.dispersionFunction == "module") {
    dispersionFunction = new dfModule<keyType>(parameters.tableSize);
  } else if (parameters.dispersionFunction == "sum") {
    dispersionFunction = new dfSum<keyType>(parameters.tableSize);
  } else if (parameters.dispersionFunction == "random") {
    dispersionFunction = new dfRandom<keyType>(parameters.tableSize);
  }

  if (parameters.dispersionTechnic == "open") {
    std::cout << "\nOpen dispersion" << std::endl;
    HashTable<keyType, DynamicSequence<keyType>> hashTable(parameters.tableSize, *dispersionFunction);
    menu(hashTable);
  } else if (parameters.dispersionTechnic == "close") {
    if (parameters.explorationFunction == "lineal") {
      explorationFunction = new efLineal<keyType>;
    } else if (parameters.explorationFunction == "double") {
      explorationFunction = new efDoubleDispersion<keyType>;
    } else if (parameters.explorationFunction == "quadratic") {
      explorationFunction = new efQuadratic<keyType>;
    } else if (parameters.explorationFunction == "redispersion") {
      explorationFunction = new efRedispersion<keyType>;
    }
    std::cout << "\nClose dispersion" << std::endl;
    HashTable<keyType, StaticSequence<keyType>> hashTable(parameters.tableSize, *dispersionFunction, *explorationFunction, parameters.blockSize);
    menu(hashTable);
  }
}

template <typename HashTableType>
void menu(HashTableType& hashTable) {
  // Check the type of hashTable
  // std::cout << typeid(hashTable).name() << std::endl;

  std::string option;
  int optionMenu;
  while (true) {
    std::cout << "\n###### Hash Table ######" << std::endl;
    std::cout << kRedBold << "  [1]." << kReset << kBold << " Insert" << std::endl;
    std::cout << kRedBold << "  [2]." << kReset << kBold << " Search" << std::endl;
    std::cout << kRedBold << "  [3]." << kReset << kBold << " Delete" << kReset << std::endl;
    std::cout << kRedBold << "  [4]." << kReset << kBold << " Print table" << std::endl;
    std::cout << kRedBold << "  [5]." << kReset << kBold << " Exit" << kReset << std::endl;
    std::cout << "Select an option: ";
    std::cin >> option;

    // If the option is of type char, display an invalid option message
    if (option.size() == 1 && isalpha(option[0])) {
      std::cout << kRedBold << "Invalid option" << kReset << std::endl;
      continue;
    } 

    // If the option is a number, convert it to an integer
    if (isalnum(option[0]) && option.size() == 1) {
      optionMenu = std::stoi(option);
    } else {
      std::cout << kRedBold << "Invalid option" << kReset << std::endl;
      continue;
    }

    // If the option is a string that is not a number, display an invalid option message
    if (option.size() > 1) {
      std::cout << kRedBold << "Invalid option" << kReset << std::endl;
      continue;
    }

    // system("clear");

    switch (optionMenu) {
      case 1: {
        keyType key;
        std::cout << kBold << "Enter the key to insert: " << kReset;
        std::cin >> key;
        hashTable.insert(key);
        hashTable.print();
        break;
      }
      case 2: {
        keyType key;
        std::cout << kBold << "Enter the key to search" << kReset;
        std::cin >> key;
        if (!hashTable.search(key)) {
          std::cout << "The key " << kCyanBold << key << kReset << kRedBold << " is not" << kReset << " on the table." << kReset << std::endl << std::endl;
        } else {
          std::cout << "The key " << kCyanBold << key << kReset << kGreenBold << " is" << kReset << " on the table." << kReset << std::endl << std::endl;
        }
        break;
      }
      case 3: {
        keyType key;
        std::cout << kBold << "Enter the key to remove " << kReset;
        std::cin >> key;
        hashTable.remove(key);
        hashTable.print();
        break;
      }
      case 4:
        std::cout << kBold << "Hash Table: " << kReset << std::endl;
        hashTable.print();
        break; 
      case 5:
        std::cout << kBold << "Exiting..." << kReset << std::endl;
        exit(EXIT_SUCCESS);
      dexplorationFunctionault:
        std::cout << kRedBold << "Invalid option" << kReset << std::endl;
        break;
    }
  }
}