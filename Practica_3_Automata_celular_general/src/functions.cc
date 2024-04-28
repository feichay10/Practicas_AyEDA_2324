/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file functions.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/functions.h"

void checkParameters(int argc, char* argv[], parameters& params) {
  if (argc == 2 && std::string(argv[1]) == "-help") {
    throw kUsage;
    exit(EXIT_FAILURE);
  } else if (argc == 1) {
    throw std::invalid_argument("No arguments provided. Use " + std::string(argv[0]) + " -help for more information.");
    exit(EXIT_FAILURE);
  }


  for (int i = 0; i < argc; i++) {
    
  }

  for (int i = 0; i < argc; i++) {
    if (std::string(argv[i]) == "-dim") {
      params.dimension = std::stoi(argv[i + 1]);
    } else if (std::string(argv[i]) == "-size") {
      if (params.dimension == 1) {
        params.rows = std::stoi(argv[i + 1]);
      } else if (params.dimension == 2) {
        params.rows = std::stoi(argv[i + 1]);
        params.columns = std::stoi(argv[i + 2]);
      }
    } else if (std::string(argv[i]) == "-init") {
      params.flagFile = true;
      params.file = argv[i + 1];

      std::ifstream file(params.file);
      if (!file.is_open()) {
        throw std::invalid_argument("Error: File not found.");
        exit(EXIT_FAILURE);
      }

      std::string line;
      file >> params.dimension;
      if (params.dimension == 1) {
        file >> params.rows;
      } else if (params.dimension == 2) {
        file >> params.columns;
        file >> line;
        file >> params.rows;
      }
    } else if (std::string(argv[i]) == "-cell") {
      if (std::string(argv[i + 1]) == "ACE30") {
        params.factory = new FactoryCellACE30();
      } else if (std::string(argv[i + 1]) == "ACE110") {
        params.factory = new FactoryCellACE110();
      }
    } else if (std::string(argv[i]) == "-border") {
      if (std::string(argv[i + 1]) == "open") {
        params.border_Type = static_cast<borderType>(0);
        if (std::string(argv[i + 2]) == "0") {
          params.open_BorderType = static_cast<openBorderType>(0);
        } else if (std::string(argv[i + 2]) == "1") {
          params.open_BorderType = static_cast<openBorderType>(1);
        }
      } else if (std::string(argv[i + 1]) == "periodic") {
        params.border_Type = static_cast<borderType>(1);
      } 
    }
  }
}

void createLattice(parameters& params) {
  Lattice* lattice;
  if (params.dimension == 1) {
    if (params.border_Type == 0) {
      if (params.flagFile) {
        lattice = new Lattice1D_Open(params.file, params.factory, params.open_BorderType);
      } else {
        lattice = new Lattice1D_Open(params.rows, params.factory, params.open_BorderType);
      }
    } else if (params.border_Type == 1) { 
      if (params.flagFile) {
        std::cout << "Periodic file" << std::endl;
        lattice = new Lattice1D_Periodic(params.file, params.factory);
      } else {
        std::cout << "Periodic rows" << std::endl;
        lattice = new Lattice1D_Periodic(params.rows, params.factory);
      }
    }
  } 
  
  menu(*lattice);
}

void textMenu() {
  std::cout << BOLD << "\nAvailable commands: " << RESET << std::endl;
  std::cout << RED_BOLD << "  [x]" << RESET << " Exit the program." << std::endl;
  std::cout << RED_BOLD << "  [n]" << RESET << " Show the next generation." << std::endl;
  std::cout << RED_BOLD << "  [L]" << RESET << " Show the next 5 generations." << std::endl;
  std::cout << RED_BOLD << "  [c]" << RESET << " Show only the population." << std::endl;
  std::cout << RED_BOLD << "  [s]" << RESET << " Save the current configuration to a file." << std::endl;
  std::cout << RED_BOLD << "  [a]" << RESET << " Automatic generation." << std::endl << std::endl;
}

void menu(Lattice &lattice) {
  char command;
  bool commandFlag = false;
  
  std::cout << lattice << std::endl;

  textMenu();
  
  do {
    std::cout << "Enter a command: ";
    std::cin >> command;
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
        std::cout << "\tCurrent population: " << lattice.Population() << std::endl;
        break;
      case 'L':
        std::cout << "Next 5 generations: " << std::endl;
        for (int i = 0; i < 5; i++) {
          lattice.nextGeneration();
          if (!commandFlag) {
            std::cout << lattice;
          }
          std::cout << "\tCurrent population: " << lattice.Population() << std::endl;
        }
        break;
      case 'c':
        std::cout << "Current population: " << lattice.Population() << std::endl;
        if (!commandFlag) {
          commandFlag = true;
        } else {
          commandFlag = false;
        }
        break;
      case 's': {
          std::string fileName;
          std::cout << "Enter the file name: ";
          std::cin >> fileName;
          std::ofstream fileOut(fileName);
          fileOut << lattice;
        }
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
  std::cout << "\nUse 'Enter' to continue the generation" << std::endl;
  std::cout << "Use 'q' to end the cell evolution" << std::endl << std::endl;
  std::cout << lattice << std::endl;
  // Limpiar el búfer de entrada para descartar el carácter de nueva línea
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  while (true) {
    lattice.nextGeneration();
    std::cout << lattice;
    if (std::cin.get() == 'q') {
      break;
    }
  }
}