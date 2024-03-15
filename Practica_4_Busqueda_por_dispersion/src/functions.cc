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

  std::cout << kPurpleBold << "+------------------------------------+" << std::endl;
  std::cout << "|          " << kReset << kCyanBold << "Hash Information" << kReset << kPurpleBold << "          |" << std::endl;
  std::cout << "+------------------------------------+"<< kReset << std::endl;
  std::cout << kPurpleBold << "|" << kReset << kGrayBold << " Table size: " << kBlueBold << parameters.tableSize << kPurpleBold << std::setw(24 - std::to_string(parameters.tableSize).length()) << "|" << kReset << std::endl;
  std::cout << kPurpleBold << "|" << kReset << kGrayBold << " Dispersion function: " << kBlueBold << parameters.dispersionFunction << kPurpleBold << std::setw(15 - parameters.dispersionFunction.length()) << "|" << kReset << std::endl;
  std::cout << kPurpleBold << "|" << kReset << kGrayBold << " Dispersion technic: " << kBlueBold << parameters.dispersionTechnic << kPurpleBold << std::setw(16 - parameters.dispersionTechnic.length()) << "|" << kReset << std::endl;
  if (parameters.dispersionTechnic == "close") {
    std::cout << kPurpleBold << "|" << kReset << " Block size: " << parameters.blockSize << kPurpleBold<< std::setw(24 - std::to_string(parameters.blockSize).length()) << "|" << kReset << std::endl;
    std::cout << kPurpleBold << "|" << kReset << " Exploration function: " << parameters.explorationFunction << kPurpleBold << std::setw(14 - parameters.explorationFunction.length()) << kReset << "|" << std::endl;
  }
  std::cout << kPurpleBold << "+------------------------------------+" << kReset << std::endl;

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
    HashTable<keyType, StaticSequence<keyType>> hashTable(parameters.tableSize, *dispersionFunction, *explorationFunction, parameters.blockSize);
    menu(hashTable);
  }
}

template <typename HashTableType>
void menu(HashTableType& hashTable) {
  std::string option;
  int optionMenu;
  while (true) {
    std::cout << kGrayBold << "\n###### Hash Table ######" << kReset << std::endl;
    std::cout << kRedBold << "  [1]." << kReset << kBold << " Insert" << std::endl;
    std::cout << kRedBold << "  [2]." << kReset << kBold << " Insert by file" << kReset << std::endl;
    std::cout << kRedBold << "  [3]." << kReset << kBold << " Search" << std::endl;
    std::cout << kRedBold << "  [4]." << kReset << kBold << " Remove" << kReset << std::endl;
    std::cout << kRedBold << "  [5]." << kReset << kBold << " Clear table" << kReset << std::endl;
    std::cout << kRedBold << "  [6]." << kReset << kBold << " Print table" << std::endl;
    std::cout << kRedBold << "  [7]." << kReset << kBold << " Exit" << kReset << std::endl;
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


    switch (optionMenu) {
      case 1: {
        keyType key;
        std::cout << kGrayBold << "Enter the key to insert: " << kReset;
        std::cin >> key;
        hashTable.insert(key);
        hashTable.print();
        break;
      }
      case 2: {
        std::string file;
        std::cout << kGrayBold << "Enter the file name: " << kReset;
        std::cin >> file;
        hashTable.insertByFile(file);
        hashTable.print();
        break;
      }
      case 3: {
        keyType key;
        std::cout << kGrayBold << "Enter the key to search: " << kReset;
        std::cin >> key;
        if (!hashTable.search(key)) {
          std::cout << "The key " << kCyanBold << key << kReset << kRedBold << " is not" << kReset << " on the table." << kReset << std::endl << std::endl;
        } else {
          std::cout << "The key " << kCyanBold << key << kReset << kGreenBold << " is" << kReset << " on the table." << kReset << std::endl << std::endl;
        }
        break;
      }
      case 4: {
        keyType key;
        std::cout << kGrayBold << "Enter the key to remove: " << kReset;
        std::cin >> key;
        hashTable.remove(key);
        hashTable.print();
        break;
      }
      case 5:
        hashTable.clear();
        std::cout << kGrayBold << "Table cleared" << kReset << std::endl;
        hashTable.print();
        break;
      case 6:
        std::cout << kGrayBold << "Hash Table: " << kReset << std::endl;
        hashTable.print();
        break; 
      case 7:
        std::cout << "Exiting..." << std::endl;
        exit(EXIT_SUCCESS);
      default:
        std::cout << kRedBold << "Invalid option" << kReset << std::endl;
        break;
    }
  }
}