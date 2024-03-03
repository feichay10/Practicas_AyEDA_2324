/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file cellular_automata.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

#include "../include/cell.h"
#include "../include/factoryCell.h"
#include "../include/factoryCellACE110.h"
#include "../include/functions.h"
#include "../include/lattice.h"
#include "../include/lattice1D_open.h"

int dim = 0;
int size;
int rows;
int columns;
borderType border;
std::string fileIn = "";
std::string fileOut = "";
FactoryCell* factoryCell = nullptr;
Lattice* lattice = nullptr;

void checkProgramParameters(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "-help") {
    throw kUsage;
    exit(EXIT_FAILURE);
  } else if (argc == 1) {
    throw std::string("No arguments provided. Use ") + argv[0] +
        " -help for more information.";
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-dim") {
      if (i + 1 == 1) {
        std::cout << "Automata celular elemental" << std::endl;
        dim = 1;
      } else {
        std::cout << "Automata celular, juego de la vida" << std::endl;
        dim = 2;
      }
    } else if (std::string(argv[i]) == "-size") {
      if (dim == 1) {
        size = std::stoi(argv[i + 1]);
      } else if (dim == 2) {
        rows = std::stoi(argv[i + 1]);
        columns = std::stoi(argv[i + 2]);
      }
    } else if (std::string(argv[i]) == "-init") {
      fileIn = argv[i + 1];
    } else if (std::string(argv[i]) == "-cell") {
      if (std::string(argv[i + 1]) == "Ace100") {
        factoryCell = new FactoryCellACE110();
      } 
    } else if (std::string(argv[i]) == "-border") {
      std::cout << "Border" << std::endl;
      if (std::string(argv[i + 1]) == "open") {
        border = kOpen;
        // lattice = new Lattice1D_Open(size, *factoryCell, kCold);
      }
    }
  }

}

int main(int argc, char* argv[]) {
  try {
    checkProgramParameters(argc, argv);
  } catch (std::string& e) {
    std::cerr << e << std::endl;
  }

  return 0;
}