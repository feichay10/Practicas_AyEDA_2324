/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 7: Implementacion del TDA AVL
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-29
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

  // Check for tree type and initialization parameters, must be provided
  bool treeType = false, init = false;
  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-ab") {
      treeType = true;
    } else if (std::string(argv[i]) == "-init") {
      init = true;
    }
  }

  if (!treeType) {
    throw std::invalid_argument("Tree type parameter not provided. Use " + std::string(argv[0]) + " -help for more information.");
  } else if (!init) {
    throw std::invalid_argument("Initialization not provided. Use " + std::string(argv[0]) + " -help for more information.");
  }

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-ab") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) == "abe" || std::string(argv[i + 1]) == "abb" || std::string(argv[i + 1]) == "ab") {
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
            parameters.file_ = argv[i + 3];
          } else {
            throw std::invalid_argument("File not provided. Use " + std::string(argv[0]) + " -help for more information.");
          }
        } else {
          throw std::invalid_argument("Initialization " + std::string(argv[i + 1]) + " not avalaible. Use " + std::string(argv[0]) + " -help for more information.");
        }
        if (parameters.init_ == "manual") {
          parameters.numberGenerated_ = 0;
        } else {
          parameters.numberGenerated_ = std::stoi(argv[i + 2]);
        }
      } else {
        throw std::invalid_argument("Initialization not provided. Use " + std::string(argv[0]) + " -help for more information.");
      }
    } 
  }

  return parameters;
}

void printInformation(treeParameters& parameters) {
  std::cout << PURPLE_BOLD << "+-----------------------------------------+" << RESET << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << ORANGE_BG << GRAY_BOLD << "             TDA Information             " << RESET << PURPLE_BOLD << "|" << std::endl;
  std::cout << PURPLE_BOLD << "+-----------------------------------------+" << RESET << std::endl;
  
  std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
            << " Tree type: " << BLUE_BOLD
            << (parameters.treeType_ == "abe" ? "Balanced binary tree (ABE)" : "Binary search tree (ABB)")
            << PURPLE_BOLD
            << std::setw(25 - (parameters.treeType_ == "abe" ? 21 : 19)) << "|" << RESET << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
            << " Initialization: " << BLUE_BOLD
            << parameters.init_ << PURPLE_BOLD
            << std::setw(25 - parameters.init_.length()) << "|"
            << RESET << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
            << " Number of elements: " << BLUE_BOLD
            << parameters.numberGenerated_ << PURPLE_BOLD
            << std::setw(21 - std::to_string(parameters.numberGenerated_).length())
            << "|" << RESET << std::endl;
  if (parameters.init_ == "file") {
    std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
              << " File: " << BLUE_BOLD << parameters.file_
              << PURPLE_BOLD
              << std::setw(35 - parameters.file_.length())
              << "|" << RESET << std::endl;
  }
  std::cout << PURPLE_BOLD << "+-----------------------------------------+" << RESET << std::endl;
}

void createTree(treeParameters& parameters) {
  AB<keyType>* tree;
  if (parameters.treeType_ == "abe") {
    tree = new ABE<keyType>();
  } else if (parameters.treeType_ == "abb") {
    tree = new ABB<keyType>();
  } else {
    tree = new ABLevel<keyType>();
  }

  if (parameters.init_ == "random") {
    for (int i = 0; i < parameters.numberGenerated_; i++) {
      keyType key;
      std::cout << BOLD << "\nInsert key: " << RESET << key << std::endl;
      tree->insert(key);
      tree->write(std::cout);
    }
  } else if (parameters.init_ == "file") {
    std::ifstream file(parameters.file_);
    if (!file.is_open()) {
      throw std::runtime_error("File could not be opened.");
    }

    int numElements, count = 0;
    file >> numElements;
    if (numElements != parameters.numberGenerated_) {
      throw std::length_error("Number of elements in file does not match with the number of elements provided.");
    }

    keyType key;
    while (file >> key) {
      std::cout << BOLD << "\nInsert key: " << RESET << key << std::endl;
      tree->insert(key);
      count++;
      tree->write(std::cout);
    }

    if (count != numElements) {
      throw std::length_error("Number of elements in file does not match with the number of elements provided.");
    }

    file.close();
  }

  std::cout << std::endl;
  if (tree->empty()) {
    std::cout << BOLD << "Tree is empty." << RESET << std::endl;
    tree->write(std::cout);
  }

  menu(tree, parameters);
}

void menu(AB<keyType>* tree, treeParameters& parameters) {
  int option;
  keyType key;

  while (true) {
    std::cout << BOLD << "\n\nOperations" << RESET << std::endl;
    std::cout << RED_BOLD << "  [0]" << RESET << BOLD << " Exit" << std::endl;
    std::cout << RED_BOLD << "  [1]" << RESET << BOLD << " Insert key" << std::endl;
    std::cout << RED_BOLD << "  [2]" << RESET << BOLD << " Search key" << std::endl;
    std::cout << RED_BOLD << "  [3]" << RESET << BOLD << " Delete key" << std::endl;
    std::cout << RED_BOLD << "  [4]" << RESET << BOLD << " Show inorder tree" << std::endl;
    std::cout << RED_BOLD << "  [5]" << RESET << BOLD << " Show preorder tree" << std::endl;
    std::cout << RED_BOLD << "  [6]" << RESET << BOLD << " Show postorder tree" << std::endl;
    std::cout << RED_BOLD << "  [7]" << RESET << BOLD << " Show by level order tree" << std::endl;
    std::cout << RED_BOLD << "  [8]" << RESET << BOLD << " Show all properties" << std::endl;
    std::cout << RED_BOLD << "  [9]" << RESET << BOLD << " Show tree" << std::endl;
    std::cout << "Select operation: " << RESET; 
    std::cin >> option;

    switch (option) {
      case 0:
        std::cout << BOLD << "\nExiting program..." << RESET << std::endl;
        exit(EXIT_SUCCESS);
        break;
      case 1:
        std::cout << BOLD << "\nInsert key: " << RESET;
        std::cin >> key;
        if (!tree->insert(key)) {
          std::cout << RED_BOLD << "Key already exists." << RESET << std::endl << std::endl;
        }
        tree->write(std::cout);
        break;
      case 2:
        std::cout << BOLD << "\nSearch key: " << RESET;
        std::cin >> key;
        if (tree->search(key)) {
          std::cout << GREEN_BOLD << "Key found." << RESET << std::endl;
        } else {
          std::cout << RED_BOLD << "Key not found." << RESET << std::endl;
        }
        break;
      case 3:
        if (parameters.treeType_ == "abe") {
          std::cout << RED_BOLD << "\nDelete key operation not available for ABE tree." << RESET << std::endl;
        } else {
          std::cout << BOLD << "\nDelete key: " << RESET;
          std::cin >> key;
          if (!tree->remove(key)) {
            std::cout << RED_BOLD << "Key not found." << RESET << std::endl << std::endl;
          }
          tree->write(std::cout);
        }
        break;
      case 4:
        std::cout << BOLD << "\nInorder tree: " << RESET;
        tree->inorder();
        std::cout << std::endl;
        break;
      case 5:
        std::cout << BOLD << "\nPreorder tree: " << RESET;
        tree->preorder();
        std::cout << std::endl;
        break;
      case 6:
        std::cout << BOLD << "\nPostorder tree: " << RESET;
        tree->postorder();
        std::cout << std::endl;
        break;
      case 7:
        std::cout << BOLD << "\nBy level tree: " << RESET;
        tree->byLevel();
        std::cout << std::endl;
        break;
      case 8:
        std::cout << BOLD << "\nTree properties: " << RESET << std::endl;
        std::cout << " -Tree: " << std::endl;
        tree->write(std::cout);
        std::cout << "\n -Height: " << BLUE_BOLD << tree->height() << RESET << std::endl;
        std::cout << " -Number of nodes: " << BLUE_BOLD << tree->getNodes() << RESET << std::endl;
        std::cout << " -Number of leaves: " << BLUE_BOLD << tree->getLeafCount() << RESET << std::endl;
        std::cout << " -Preorder tree: " << BLUE_BOLD;
        tree->preorder();
        std::cout << RESET << std::endl;
        std::cout << " -Postorder tree: " << BLUE_BOLD;
        tree->postorder();
        std::cout << RESET << std::endl;
        std::cout << " -Inorder tree: " << BLUE_BOLD;
        tree->inorder();
        std::cout << RESET << std::endl;
        std::cout << " -By level tree: " << BLUE_BOLD;
        tree->byLevel();
        std::cout << RESET << std::endl;
        break;
      case 9:
        std::cout << BOLD << "\nTree: " << RESET << std::endl;
        tree->write(std::cout); 
        break;
      default:
        std::cout << RED_BOLD << "\nInvalid option." << RESET << std::endl;
        std::cout << "Please select a valid option." << std::endl;
    }
  }
}