/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementacion del TDA Árbol
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/functions.h"

treeParameters checkProgramParameters(int argc, char* argv[], treeParameters& parameters) {
  if (argc == 2 && std::string(argv[1]) == "-help") {
    std::cout << kUsage << std::endl;
    exit(EXIT_SUCCESS);
  } else if (argc == 1) {
    throw std::runtime_error("No arguments provided. Use " + std::string(argv[0]) + " -help for more information.");
  }

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-ab") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) == "abe" || std::string(argv[i + 1]) == "abb") {
          parameters.treeType_ = argv[i + 1];
        } else {
          throw std::invalid_argument("Tree type " + std::string(argv[i + 1]) + " not avalaible. Use " + std::string(argv[0]) + " -help for more information.");
        }
      } else {
        throw std::invalid_argument("Tree type not provided. Use " + std::string(argv[0]) + " -help for more information.");
      }
    } else if (std::string(argv[i]) == "-init") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) == "manual" || std::string(argv[i + 1]) == "random") {
          parameters.init_ = argv[i + 1];
        } else if (std::string(argv[i + 1]) == "file") {
          if (i + 2 < argc) {
            parameters.init_ = argv[i + 1];
            // parameters.file_ = argv[i + 2];
            parameters.file_ = argv[i + 3];
            if (!std::filesystem::exists(parameters.file_)) {
              throw std::invalid_argument("File does not exist. Use " + std::string(argv[0]) + " -help for more information.");
            }
          } else {
            throw std::invalid_argument("File not provided. Use " + std::string(argv[0]) + " -help for more information.");
          }
        } else {
          throw std::invalid_argument("Initialization " + std::string(argv[i + 1]) + " not avalaible. Use " + std::string(argv[0]) + " -help for more information.");
        }
        parameters.numberGenerated_ = std::stoi(argv[i + 2]);
      } else {
        throw std::invalid_argument("Initialization not provided. Use " + std::string(argv[0]) + " -help for more information.");
      }
    }
  }

  return parameters;
}

void printInformation(treeParameters& parameters) {
  std::cout << PURPLE_BOLD << "+------------------------------------+" << RESET << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << ORANGE_BG << GRAY_BOLD << "           TDA Information          " << RESET << PURPLE_BOLD << "|" << std::endl;
  std::cout << "+------------------------------------+" << RESET << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
            << " Tree type: " << BLUE_BOLD << parameters.treeType_ << RESET
            << PURPLE_BOLD
            << std::setw(25 - parameters.treeType_.size()) << "|" << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
            << " Initialization: " << BLUE_BOLD
            << parameters.init_ << PURPLE_BOLD
            << std::setw(20 - parameters.init_.length()) << "|"
            << RESET << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
            << " Number of elements: " << BLUE_BOLD
            << parameters.numberGenerated_ << PURPLE_BOLD
            << std::setw(16 - std::to_string(parameters.numberGenerated_).length())
            << "|" << RESET << std::endl;
  if (parameters.init_ == "file") {
    std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
              << " File: " << BLUE_BOLD << parameters.file_
              << PURPLE_BOLD
              << std::setw(30 - parameters.file_.length())
              << "|" << RESET << std::endl;
  }
  std::cout << PURPLE_BOLD << "+------------------------------------+" << RESET << std::endl;
}

void createTree(treeParameters& parameters) {
  AB<keyType>* tree;
  if (parameters.treeType_ == "abe") {
    // tree = new ABE<keyType>();
  } else {
    tree = new ABB<keyType>();
  }

  if (tree->empty()) {
    std::cout << "Tree is empty." << std::endl;
  } else {
    std::cout << "Tree is not empty." << std::endl;
  }

  tree->write(std::cout);

  if (parameters.init_ == "manual") {
    for (int i = 0; i < parameters.numberGenerated_; i++) {
      keyType key;
      std::cout << BOLD << "Insert key: " << RESET;
      std::cin >> key;
      tree->insert(key);
      tree->write(std::cout);
      std::cout << std::endl;
    }
  } else if (parameters.init_ == "random") {
    for (int i = 0; i < parameters.numberGenerated_; i++) {
      keyType key;
      std::cout << BOLD << "Insert key: " << RESET;
      tree->insert(key);
    }
  } else { // file
    std::ifstream file(parameters.file_);
    if (!file.is_open()) {
      throw std::runtime_error("File could not be opened.");
    }

    keyType key;
    while (file >> key) {
      tree->insert(key);
    }
  }

  menu(tree);
}

void menu(AB<keyType>* tree) {
  int option;
  keyType key;

  while (true) {
    std::cout << BOLD << "\n\nOperations" << RESET << std::endl;
    std::cout << RED_BOLD << "  [0]" << RESET << BOLD << " Exit" << std::endl;
    std::cout << RED_BOLD << "  [1]" << RESET << BOLD << " Insert key" << std::endl;
    std::cout << RED_BOLD << "  [2]" << RESET << BOLD << " Search key" << std::endl;
    std::cout << RED_BOLD << "  [3]" << RESET << BOLD << " Show inorden tree" << std::endl;
    std::cout << " Select operation: " << RESET; 
    std::cin >> option;

    switch (option) {
      case 0:
        exit(EXIT_SUCCESS);
        break;
      case 1:
        std::cout << BOLD << "\nInsert key: " << RESET;
        std::cin >> key;
        // tree->insert();
        break;
      case 2:
        std::cout << BOLD << "\nSearch key: " << RESET;
        // tree->search();
        break;
      case 3:
        std::cout << BOLD << "\nInorden tree: " << RESET;
        // tree->inorden();
        break;
      default:
        std::cerr << RED_BOLD << "ERROR: " << RESET << "Invalid option." << std::endl;
        break;
    }

    // tree->write();
  }
}