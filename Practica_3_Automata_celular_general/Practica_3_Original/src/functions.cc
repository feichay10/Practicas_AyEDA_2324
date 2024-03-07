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
        std::cout << "\tCurrent population: " << lattice.Population() << std::endl;
        break;
      case 'L':
        std::cout << "Next 5 generations: " << std::endl;
        for (int i = 0; i < 5; i++) {
          lattice.nextGeneration();
          if (!commandFlag) {
            std::cout << lattice;
          }
          // std::cout << "Generation: " << lattice.getGeneration() << std::endl << std::endl;
          std::cout << "\tCurrent population: " << lattice.Population() << std::endl;
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