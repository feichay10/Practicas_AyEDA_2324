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
    throw std::invalid_argument("No arguments provided. Use " + std::string(argv[0]) + " -help for more information.");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-ts") {
      if (i + 1 < argc) {
        if (std::stoi(argv[i + 1]) < 1) {
          throw std::invalid_argument("Invalid table size. Table size must be greater than 0.");
          exit(EXIT_FAILURE);
        } else {
          parameters.tableSize = std::stoi(argv[i + 1]);
        }
      } else {
        throw std::invalid_argument("Table size not provided.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-fd") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) != "module" &&
            std::string(argv[i + 1]) != "sum" &&
            std::string(argv[i + 1]) != "random") {
          throw std::invalid_argument("Invalid dispersion function. Use random or sum.");
          exit(EXIT_FAILURE);
        } else {
          parameters.dispersionFunction = std::string(argv[i + 1]);
        }
      }
    } else if (std::string(argv[i]) == "-hash") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) != "open" &&
            std::string(argv[i + 1]) != "close") {
          throw std::invalid_argument("Invalid dispersion technic. Use open or closed.");
          exit(EXIT_FAILURE);
        } else {
          parameters.dispersionTechnic = std::string(argv[i + 1]);
        }
      }
    } else if (std::string(argv[i]) == "-bs") {
      if (i + 1 < argc) {
        if (std::stoi(argv[i + 1]) < 1) {
          throw std::invalid_argument("Invalid block size. Block size must be greater than 0.");
          exit(EXIT_FAILURE);
        } else {
          if (std::stoi(argv[i + 1]) > parameters.tableSize) {
            throw std::invalid_argument("Invalid block size. Block size must be less than the table size.");
            exit(EXIT_FAILURE);
          } else {
            parameters.blockSize = std::stoi(argv[i + 1]);
          }
        }
      } else {
        throw std::invalid_argument("Block size not provided."); 
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-fe") {
      if (std::string(argv[i + 1]) == "lineal" ||
          std::string(argv[i + 1]) == "quadratic" ||
          std::string(argv[i + 1]) == "double" ||
          std::string(argv[i + 1]) == "redispersion") {
        if (std::string(argv[i + 1]) == "double") {
          parameters.dfForExploration = std::string(argv[i + 2]);
          if (std::string(argv[i + 2]) != "module" &&
              std::string(argv[i + 2]) != "sum" &&
              std::string(argv[i + 2]) != "random") {
            throw std::invalid_argument("Invalid exploration function. Use module, sum or random.");
            exit(EXIT_FAILURE);
          }
        }
        parameters.explorationFunction = std::string(argv[i + 1]);
      } else {
        throw std::invalid_argument("Invalid exploration function. Use lineal, quadratic, double or redispersion.");
        exit(EXIT_FAILURE);
      }
    }
  }

  // Set default values
  if (parameters.dispersionFunction == "") {
    parameters.dispersionFunction = "module";
  } else if (parameters.dispersionTechnic == "") {
    parameters.dispersionTechnic = "open";
  } else if (parameters.explorationFunction == "") {
    parameters.explorationFunction = "lineal";
  }

  std::cout << PURPLE_BOLD << "+----------------------------------------------+" << RESET << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << ORANGE_BG << GRAY_BOLD << "               Hash Information               " << RESET << PURPLE_BOLD << "|" << std::endl;
  std::cout << "+----------------------------------------------+" << RESET << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
            << " Table size: " << BLUE_BOLD << parameters.tableSize
            << PURPLE_BOLD
            << std::setw(34 - std::to_string(parameters.tableSize).length())
            << "|" << RESET << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
            << " Dispersion function: " << BLUE_BOLD
            << parameters.dispersionFunction << PURPLE_BOLD
            << std::setw(25 - parameters.dispersionFunction.length()) << "|"
            << RESET << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
            << " Dispersion technic: " << BLUE_BOLD
            << parameters.dispersionTechnic << PURPLE_BOLD
            << std::setw(26 - parameters.dispersionTechnic.length()) << "|"
            << RESET << std::endl;
  if (parameters.dispersionTechnic == "close") {
    std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
              << " Block size: " << BLUE_BOLD << parameters.blockSize
              << PURPLE_BOLD
              << std::setw(34 - std::to_string(parameters.blockSize).length())
              << "|" << RESET << std::endl;
    std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
              << " Exploration function: " << BLUE_BOLD
              << parameters.explorationFunction << RESET << PURPLE_BOLD
              << std::setw(24 - parameters.explorationFunction.length()) << "|"
              << RESET << std::endl;
    if (parameters.explorationFunction == "double") {
      std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
                << " Dispersion function for exploration: " << BLUE_BOLD
                << parameters.dfForExploration << PURPLE_BOLD
                << std::setw(9 - parameters.dfForExploration.length()) << "|"
                << RESET << std::endl;
    }
  }
  std::cout << PURPLE_BOLD << "+----------------------------------------------+" << RESET
            << std::endl;

  return parameters;
}

void makeHashTable(HashTableParameters& parameters) {
  DispersionFunction<keyType>* dispersionFunction;
  DispersionFunction<keyType>* dfForExploration;
  ExplorationFunction<keyType>* explorationFunction;

  if (parameters.dispersionFunction == "module") {
    dispersionFunction = new dfModule<keyType>(parameters.tableSize);
  } else if (parameters.dispersionFunction == "sum") {
    dispersionFunction = new dfSum<keyType>(parameters.tableSize);
  } else if (parameters.dispersionFunction == "random") {
    dispersionFunction = new dfRandom<keyType>(parameters.tableSize);
  }

  if (parameters.dispersionTechnic == "open") {
    HashTable<keyType, DynamicSequence<keyType>> hashTable(parameters.tableSize, *dispersionFunction);
    menu(hashTable);
  } else if (parameters.dispersionTechnic == "close") {
    if (parameters.explorationFunction == "lineal") {
      explorationFunction = new efLineal<keyType>;
    } else if (parameters.explorationFunction == "double") {
      if (parameters.dfForExploration == "module") {
        dfForExploration = new dfModule<keyType>(parameters.tableSize);
      } else if (parameters.dfForExploration == "sum") {
        dfForExploration = new dfSum<keyType>(parameters.tableSize);
      } else if (parameters.dfForExploration == "random") {
        dfForExploration = new dfRandom<keyType>(parameters.tableSize);
      }
      explorationFunction = new efDoubleDispersion<keyType>(dfForExploration);
    } else if (parameters.explorationFunction == "quadratic") {
      explorationFunction = new efQuadratic<keyType>;
    } else if (parameters.explorationFunction == "redispersion") {
      explorationFunction = new efRedispersion<keyType>(dfForExploration);
    }
    HashTable<keyType, StaticSequence<keyType>> hashTable(parameters.tableSize, *dispersionFunction, *explorationFunction, parameters.blockSize);
    menu(hashTable);
  }
}

template <typename HashTableType>
void menu(HashTableType& hashTable) {
  std::string option;
  int optionMenu;
  while (true) {
    std::cout << GRAY_BOLD << "\n###### Hash Table ######" << RESET
              << std::endl;
    std::cout << RED_BOLD << "  [1]." << RESET << BOLD << " Insert"
              << std::endl;
    std::cout << RED_BOLD << "  [2]." << RESET << BOLD << " Insert by file"
              << RESET << std::endl;
    std::cout << RED_BOLD << "  [3]." << RESET << BOLD << " Search"
              << std::endl;
    std::cout << RED_BOLD << "  [4]." << RESET << BOLD << " Remove" << RESET
              << std::endl;
    std::cout << RED_BOLD << "  [5]." << RESET << BOLD << " Clear table"
              << RESET << std::endl;
    std::cout << RED_BOLD << "  [6]." << RESET << BOLD << " Print table"
              << std::endl;
    std::cout << RED_BOLD << "  [7]." << RESET << BOLD << " Exit" << RESET
              << std::endl;
    std::cout << "Select an option: ";
    std::cin >> option;

    // If the option is of type char, display an invalid option message
    if (option.size() == 1 && isalpha(option[0])) {
      std::cout << RED_BOLD << "Invalid option" << RESET << std::endl;
      continue;
    }

    // If the option is a number, convert it to an integer
    if (isalnum(option[0]) && option.size() == 1) {
      optionMenu = std::stoi(option);
    } else {
      std::cout << RED_BOLD << "Invalid option" << RESET << std::endl;
      continue;
    }

    // If the option is a string that is not a number, display an invalid option
    // message
    if (option.size() > 1) {
      std::cout << RED_BOLD << "Invalid option" << RESET << std::endl;
      continue;
    }

    switch (optionMenu) {
      case 1: {
        std::cout << std::endl;
        keyType key;
        std::cout << GRAY_BOLD << "Enter the key to insert: " << RESET << GOLD;
        std::cin >> key;
        std::cout << RESET;
        if (!key.checkNif(key)) {
          std::cout << RED_BOLD << "Invalid NIF. The NIF must have 8 digits." << RESET << std::endl;
          break;
        }
        hashTable.insert(key);
        hashTable.print();
        break;
      }
      case 2: {
        std::cout << std::endl;
        std::string file;
        std::cout << GRAY_BOLD << "Enter the file name: " << RESET << GOLD;
        std::cin >> file;
        std::cout << RESET;
        hashTable.insertByFile(file);
        hashTable.print();
        break;
      }
      case 3: {
        std::cout << std::endl;
        keyType key;
        std::cout << GRAY_BOLD << "Enter the key to search: " << RESET << GOLD;
        std::cin >> key;
        std::cout << RESET;
        if (!key.checkNif(key)) {
          std::cout << RED_BOLD << "Invalid NIF. The NIF must have 8 digits." << RESET << std::endl;
          break;
        }
        if (!hashTable.search(key)) {
          std::cout << "The key " << CYAN_BOLD << key << RESET << RED_BOLD
                    << " is not" << RESET << " on the table." << RESET
                    << std::endl
                    << std::endl;
        } else {
          std::cout << "The key " << CYAN_BOLD << key << RESET << GREEN_BOLD
                    << " is" << RESET << " on the table." << RESET
                    << std::endl
                    << std::endl;
        }
        break;
      }
      case 4: {
        std::cout << std::endl;
        keyType key;
        std::cout << GRAY_BOLD << "Enter the key to remove: " << RESET << GOLD;
        std::cin >> key;
        std::cout << RESET;
        if (!key.checkNif(key)) {
          std::cout << RED_BOLD << "Invalid NIF. The NIF must have 8 digits." << RESET << std::endl;
          break;
        }
        hashTable.remove(key);
        hashTable.print();
        break;
      }
      case 5: {
        std::string option;
        std::cout << std::endl;
        std::cout << GRAY_BOLD << "¿Are you sure you want to clear the table? (y/n): " << RESET << GOLD;
        std::cin >> option;
        std::cout << RESET;
        if (option == "y" || option == "Y") {
          hashTable.clear();
          std::cout << GRAY_BOLD << "Table cleared" << RESET << std::endl;
          hashTable.print();
        } else if (option == "n" || option == "N") {
          std::cout << GRAY_BOLD << "Table not cleared" << RESET << std::endl;
        } else {
          std::cout << RED_BOLD << "Invalid option" << RESET << std::endl;
        }
        break;
      }
      case 6:
        std::cout << std::endl;
        std::cout << GRAY_BOLD << "Hash Table: " << RESET << std::endl;
        hashTable.print();
        break;
      case 7:
        std::cout << "Exiting..." << std::endl;
        exit(EXIT_SUCCESS);
      default:
        std::cout << RED_BOLD << "Invalid option" << RESET << std::endl;
        break;
    }
  }
}