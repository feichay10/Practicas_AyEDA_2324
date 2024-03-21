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

  // a. -size <s>, s es el tamaño de la secuencia.
  // b. -ord <m>, m es el código que identifica un método de ordenación.
  // c. -init <i> [f], indica la forma de introducir los datos de la secuencia
  // i=manual
  // i=random
  // i=file f=nombre del fichero de entrada
  // d. -trace <y|n>, indica si se muestra o no la traza durante la ejecución
  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-size") {
      if (i + 1 < argc) {
        parameters.size_ = std::stoi(argv[i + 1]);
      } else {
        throw std::invalid_argument("Size not provided. Use " + std::string(argv[0]) + " -help for more information.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-ord") {
      if (i + 1 < argc) {
        parameters.order_ = argv[i + 1];
      } else {
        throw std::invalid_argument("Order not provided. Use " + std::string(argv[0]) + " -help for more information.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-init") {
      if (i + 1 < argc) {
        parameters.init_ = argv[i + 1];
        if (parameters.init_ == "file") {
          if (i + 2 < argc) {
            parameters.file_ = argv[i + 2];
          } else {
            throw std::invalid_argument("File not provided. Use " + std::string(argv[0]) + " -help for more information.");
            exit(EXIT_FAILURE);
          }
        }
      } else {
        throw std::invalid_argument("Initialization not provided. Use " + std::string(argv[0]) + " -help for more information.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-trace") {
      if (i + 1 < argc) {
        parameters.trace_ = argv[i + 1];
      } else {
        throw std::invalid_argument("Trace not provided. Use " + std::string(argv[0]) + " -help for more information.");
        exit(EXIT_FAILURE);
      }
    }
  }
}