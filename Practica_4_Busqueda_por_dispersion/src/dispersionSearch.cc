/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file dispersionSearch.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

#include "../include/functions.h"
#include "../include/nif.h"


typedef Nif KeyType;

void checkProgramParameters(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "-help") {
    throw kUsage;
    exit(EXIT_FAILURE);
  } else if (argc == 1) {
    throw std::string("No arguments provided. Use ") + argv[0] + " -help for more information.";
    exit(EXIT_FAILURE);
  }


}

int main(int argc, char* argv[]) {
  try {
    checkProgramParameters(argc, argv);
  } catch (std::string& e) {
    std::cerr << kRedBold << "Error: " << e << kReset << std::endl;
    return 1;
  }
}