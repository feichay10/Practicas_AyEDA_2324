/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/functions.h"

sortParameters checkProgramParameters(int argc, char* argv[], sortParameters parameters) {
  if (argc == 2 && std::string(argv[1]) == "-help") {
    throw kUsage;
    exit(EXIT_FAILURE);
  } else if (argc == 1) {
    throw std::invalid_argument("No arguments provided. Use " + std::string(argv[0]) + " -help for more information.");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-size") {
      if (i + 1 < argc) {
        try {
          parameters.size_ = std::stoi(argv[i + 1]);
        } catch (std::invalid_argument& e) {
          throw std::invalid_argument("Size must be an integer. Use " + std::string(argv[0]) + " -help for more information.");
          exit(EXIT_FAILURE);
        }
        if (parameters.size_ <= 0) {
          throw std::invalid_argument("Size must be greater than 0. Use " + std::string(argv[0]) + " -help for more information.");
          exit(EXIT_FAILURE);
        }
      } else {
        throw std::invalid_argument("Size not provided. Use " + std::string(argv[0]) + " -help for more information.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-ord") {
      if (i + 1 < argc) {
        if (kAvailableOrders.find(argv[i + 1]) != kAvailableOrders.end()) {
          parameters.order_ = argv[i + 1];
        } else {
          throw std::invalid_argument("Order algorithm not available. Use " + std::string(argv[0]) + " -help for more information.");
          exit(EXIT_FAILURE);
        }
      } else {
        throw std::invalid_argument("Order algorithm not provided. Use " + std::string(argv[0]) + " -help for more information.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-init") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) == "manual" || std::string(argv[i + 1]) == "random") {
          parameters.init_ = argv[i + 1];
        } else if (std::string(argv[i + 1]) == "file") {
          if (i + 2 < argc) {
            parameters.init_ = argv[i + 1];
            parameters.file_ = argv[i + 2];
            if (!std::filesystem::exists(parameters.file_)) {
              throw std::invalid_argument("File does not exist. Use " + std::string(argv[0]) + " -help for more information.");
              exit(EXIT_FAILURE);
            }
          } else {
            throw std::invalid_argument("File not provided. Use " + std::string(argv[0]) + " -help for more information.");
            exit(EXIT_FAILURE);
          }
        } else {
          throw std::invalid_argument("Initialization not provided. Use " + std::string(argv[0]) + " -help for more information.");
          exit(EXIT_FAILURE);
        }
      } else {
        throw std::invalid_argument("Initialization not provided. Use " + std::string(argv[0]) + " -help for more information.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-trace") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) == "y" || std::string(argv[i + 1]) == "Y") {
          parameters.trace_ = true;
        } else if (std::string(argv[i + 1]) == "n" || std::string(argv[i + 1]) == "N") {
          parameters.trace_ = false;
        } else {
          throw std::invalid_argument("Option for -trace not available. Use " + std::string(argv[0]) + " -help for more information.");
          exit(EXIT_FAILURE);
        }
      } else {
        throw std::invalid_argument("Trace not provided. Use " + std::string(argv[0]) + " -help for more information.");
        exit(EXIT_FAILURE);
      }
    }
  }

  std::cout << PURPLE_BOLD << "+------------------------------------+" << RESET << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << ORANGE_BG << GRAY_BOLD << "          Sort Information          " << RESET << PURPLE_BOLD << "|" << std::endl;
  std::cout << "+------------------------------------+" << RESET << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
            << " Sequence size: " << BLUE_BOLD << parameters.size_ << RESET
            << PURPLE_BOLD
            << std::setw(21 - std::to_string(parameters.size_).length())
            << "|" << RESET << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
            << " Order method: " << BLUE_BOLD
            << parameters.order_ << PURPLE_BOLD
            << std::setw(22 - parameters.order_.length()) << "|"
            << RESET << std::endl;
  std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
            << " Initialization: " << BLUE_BOLD
            << parameters.init_ << PURPLE_BOLD
            << std::setw(20 - parameters.init_.length()) << "|"
            << RESET << std::endl;
  if (parameters.init_ == "file") {
    std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
              << " File: " << BLUE_BOLD << parameters.file_
              << PURPLE_BOLD
              << std::setw(30 - parameters.file_.length())
              << "|" << RESET << std::endl;
  }
  std::cout << PURPLE_BOLD << "|" << RESET << GRAY_BOLD
            << " Trace: " << BLUE_BOLD
            << (parameters.trace_ ? "Yes" : "No") << PURPLE_BOLD
            << std::setw(29 - (parameters.trace_ ? 3 : 2)) << "|"
            << RESET << std::endl;
  std::cout << PURPLE_BOLD << "+------------------------------------+" << RESET
            << std::endl;

  return parameters;
}

void createSequence(sortParameters parameters) {
  SortMethod<keyType>* sortMethod;
  StaticSequence<keyType> sequence(parameters.size_);

  if (parameters.init_ == "manual") {
    std::cout << "Enter the sequence data:" << std::endl;
    for (int i = 0; i < parameters.size_; i++) {
      keyType key;
      std::cin >> key;
      std::cout << "key: " << key << std::endl;
      sequence[i] = key;
    }
  } else if (parameters.init_ == "random") {
    for (int i = 0; i < parameters.size_; i++) {
      keyType key;
      sequence[i] = key;
    }
  } else if (parameters.init_ == "file") {
    std::ifstream file(parameters.file_);
    if (!file.is_open()) {
      throw std::invalid_argument("File could not be opened.");
      exit(EXIT_FAILURE);
    }

    int sequenceSize, count = 0;
    file >> sequenceSize;
    if (sequenceSize != parameters.size_) {
      throw std::invalid_argument("Size of the sequence in the file does not match the size provided.");
      exit(EXIT_FAILURE);
    }

    while (!file.eof()) {
      keyType key;
      file >> key;
      sequence[count] = key;
      count++;
    }

    bool sorted = true;
    for (int i = 0; i < parameters.size_ - 1; i++) {
      if (sequence[i] > sequence[i + 1]) {
        sorted = false;
        break;
      }
    }

    if (sorted) {
      throw std::invalid_argument("Sequence is already sorted.");
      exit(EXIT_FAILURE);
    }

    if (count != sequenceSize) {
      throw std::invalid_argument("Size of the sequence in the file does not match with the number of elements provided.");
      exit(EXIT_FAILURE);
    }

    file.close();
  }

  if (parameters.order_ == "selection") {
    sortMethod = new Selection<keyType>(sequence, parameters.size_);
  } else if (parameters.order_ == "quick") {
    sortMethod = new QuickSort<keyType>(sequence, parameters.size_);
  } else if (parameters.order_ == "heap") {
    sortMethod = new HeapSort<keyType>(sequence, parameters.size_);
  } else if (parameters.order_ == "shell") {
    sortMethod = new ShellSort<keyType>(sequence, parameters.size_);
  } else if (parameters.order_ == "radix") {
    sortMethod = new RadixSort<keyType>(sequence, parameters.size_);
  } else if (parameters.order_ == "insertion") {
    sortMethod = new Insertion<keyType>(sequence, parameters.size_);
  } else if (parameters.order_ == "merge") {
    sortMethod = new MergeSort<keyType>(sequence, parameters.size_);
  } else if (parameters.order_ == "bin") {
    sortMethod = new BinSort<keyType>(sequence, parameters.size_);
  } else if (parameters.order_ == "bubble") {
    sortMethod = new BubbleSort<keyType>(sequence, parameters.size_);
  } else if (parameters.order_ == "shake") {
    sortMethod = new ShakeSort<keyType>(sequence, parameters.size_);
  }

  if (parameters.trace_) {
    sortMethod->setTrace(parameters.trace_);
  }

  std::cout << BOLD << "\nUnordered sequence: " << RESET;
  std::cout << RED_BOLD;
  sortMethod->print();
  std::cout << RESET << std::endl;
  sortMethod->Sort();
  std::cout << BOLD << "\nSorted sequence:    " << RESET;
  std::cout << GREEN_BOLD;
  sortMethod->print();
  std::cout << RESET;
}

void checkFileContent(std::string file) {
  std::ifstream fileStream(file);
  if (!fileStream.is_open()) {
    throw std::invalid_argument("File could not be opened.");
    exit(EXIT_FAILURE);
  }

  int sequenceSize;
  fileStream >> sequenceSize;
  if (sequenceSize <= 0) {
    throw std::invalid_argument("Size of the sequence must be greater than 0.");
    exit(EXIT_FAILURE);
  }

  fileStream.close();
}