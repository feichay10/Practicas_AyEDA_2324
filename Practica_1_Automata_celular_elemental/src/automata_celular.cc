/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Autómata celular elemental
 * @file main.cc
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
#include "../include/lattice.h"
#include "../include/functions.h"

void programParameters(int argc, char* argv[]);

int size; 
borderType borderTypeVar;
openBorderType openBorderTypeVar;
std::string file = "";

int main(int argc, char* argv[]) {
  try {
    programParameters(argc, argv);
    checkSize(size, file);
    Lattice lattice(size, borderTypeVar, openBorderTypeVar, file);
    cellEvolution(lattice);
  } catch (const std::string message) { 
    std::cerr << message << std::endl;
  }

  return 0;
}

void programParameters(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    throw kUsage;
    exit(EXIT_FAILURE);
  } else if (argc == 2 && std::string(argv[1]) != "--help") {
    throw std::string("Opción no válida. Use ") + argv[0] + " --help para más información.";
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-size") {
      size = std::stoi(argv[i + 1]);
    } else if (std::string(argv[i]) == "-border") {
      borderTypeVar = (std::string(argv[i + 1]) == "open") ? kOpen : kPeriodic;
      if (borderTypeVar == kOpen) {
        openBorderTypeVar = (std::string(argv[i + 2]) == "0") ? kCold : kHot;
      }
    } else if (std::string(argv[i]) == "-init") {
      file = argv[i + 1];
    } /*else if (std::string(argv[i]) != "-size" || "-border") {
      std::cout << "Use " << argv[0] << " --help" << std::endl;
      exit(EXIT_FAILURE);
    }*/
  }
}