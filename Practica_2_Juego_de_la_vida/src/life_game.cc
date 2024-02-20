/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 2: El Juego de la Vid
 * @file life_game.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <string>

#include "../include/cell.h"
#include "../include/functions.h"
#include "../include/lattice.h"
#include "../include/position.h"

int rows, columns;
borderType borderTypeVar;
std::string fileIn = "";
std::string fileOut = "";

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
    if (std::string(argv[i]) == "-size") {
      if (i + 2 < argc) {
        rows = std::stoi(argv[i + 1]);
        columns = std::stoi(argv[i + 2]);
        i += 2;
        Lattice lattice(rows, columns);
        std::cout << "Initial lattice: " << std::endl;
        std::cout << lattice << std::endl;
      } else {
        throw std::string("Missing lattice size.");
        exit(EXIT_FAILURE);
      }
    }
  }
}

int main(int argc, char* argv[]) {
  try {
    checkProgramParameters(argc, argv);
  } catch (std::string& e) {
    std::cerr << e << std::endl;
    return 1;
  } catch (int e) {
    std::cerr << kUsage << std::endl;
    return 1;
  }

  return 0;
}