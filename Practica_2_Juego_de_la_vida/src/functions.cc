/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 2: El Juego de la Vida
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/functions.h"

void checkFile(std::string fileIn) {
  std::ifstream input(fileIn);
  if (!input.is_open()) {
    std::cerr << "Error: File could not be opened." << fileIn << std::endl;
    exit(EXIT_FAILURE);
  }

  int rows, columns;
  std::string line;
  int count = -1;
  input >> rows >> columns;
  
  // Comprobar que el tamaño de la matriz es correcto (N x M)
  if (rows <= 0 || columns <= 0) {
    throw std::string("Error: The size of the matrix is not valid, it must be greater than 0.");
    exit(EXIT_FAILURE);
  }

  // Contar el número de filas del fichero
  while (std::getline(input, line)) {
    count++;
  }

  if (count != rows) {
    throw std::string("Error: The number of rows in the file does not match the size of the matrix.");
    exit(EXIT_FAILURE);
  }

  // Contar el número de columnas del fichero, contando el número de caracteres por línea
  input.clear();
  input.seekg(0, std::ios::beg);
  int countColumns = 0;
  while (std::getline(input, line)) {
    countColumns = line.length();
  }

  if (countColumns != columns) {
    throw std::string("Error: The number of columns in the file does not match the size of the matrix.");
    exit(EXIT_FAILURE);
  }

  input.close();
}

void setBorder(const std::string& arg, borderType& borderTypeVar, Lattice &lattice) {
  if (arg == "reflective") {
    borderTypeVar = kReflective;
  } else if (arg == "noborder") {
    borderTypeVar = kNoBorder;
  } else {
    throw std::string("Invalid border type.");
    exit(EXIT_FAILURE);
  }

  lattice.setBorderType(borderTypeVar);
}

void textMenu() {
  std::cout << kBold << "\nAvailable commands: " << kReset << std::endl;
  std::cout << kRedBold << "  [x]" << kReset << " Exit the program." << std::endl;
  std::cout << kRedBold << "  [n]" << kReset << " Show the next generation." << std::endl;
  std::cout << kRedBold << "  [L]" << kReset << " Show the next 5 generations." << std::endl;
  std::cout << kRedBold << "  [c]" << kReset << " Show only the population." << std::endl;
  std::cout << kRedBold << "  [s]" << kReset << " Save the current configuration to a file." << std::endl;
  std::cout << kRedBold << "  [a]" << kReset << " Automatic generation." << std::endl << std::endl;
}

void menu(Lattice &lattice) {
  std::string fileOut;
  char command;

  std::cout << "Initial lattice: " << std::endl;
  std::cout << lattice;
  std::cout << "- Current population: " << lattice.Population() << std::endl;
  std::cout << "- Border type: " << (lattice.getBorderType() == kReflective ? "Reflective" : "No Border") << std::endl;
  textMenu();

  bool commandFlag = false;
  
  do {
    std::cout << "Enter a command: ";
    std::cin >> command;
    // system("clear");
    switch (command) {
      case 'x':
        std::cout << "Exiting the program..." << std::endl;
        exit(EXIT_SUCCESS);
        break;
      case 'n':
        std::cout << std::endl;
        lattice.nextGeneration();
        if (!commandFlag) {
          std::cout << lattice;
        }
        std::cout << "Current population: " << lattice.Population() << std::endl;
        break;
      case 'L':
        std::cout << "Initial lattice: " << std::endl;
        if (!commandFlag) {
          std::cout << lattice;
        }
        std::cout << "Current population: " << lattice.Population() << std::endl << std::endl;
        std::cout << "Next 5 generations: " << std::endl;
        for (int i = 0; i < 5; i++) {
          lattice.nextGeneration();
          if (!commandFlag) {
            std::cout << lattice;
          }
          std::cout << "Generation: " << lattice.getGeneration() << std::endl << std::endl;
          std::cout << "Current population: " << lattice.Population() << std::endl;
        }
        break;
      case 'c':
        // std::cout << "Current population: " << lattice.Population() << std::endl;
        if (!commandFlag) {
          commandFlag = true;
        } else {
          commandFlag = false;
        }
        break;
      case 's':
        std::cout << "Enter the file name: ";
        std::cin >> fileOut;
        lattice.saveToFile(fileOut);
        break;
      case 'a':
        cellEvolution(lattice);
        break;
      default:
        std::cout << "Invalid command." << std::endl;
        break;
    }
    textMenu();
  } while (true);
}

void cellEvolution(Lattice &lattice) {
  std::cout << "Use ctrl + z to exit." << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(800));

  while (true) {
    lattice.nextGeneration();
    std::cout << lattice;
    std::cout << "Generation: " << lattice.getGeneration() << std::endl;
    std::cout << "Current Population: " << lattice.Population() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    system("clear");
  }
}