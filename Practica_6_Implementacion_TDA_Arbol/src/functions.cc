/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementacion del TDA Árbol
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-22
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

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-ab") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) == "abe" || std::string(argv[i + 1]) == "abb") {
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
            // parameters.file_ = argv[i + 2];
            parameters.file_ = argv[i + 3];
            if (!std::filesystem::exists(parameters.file_)) {
              throw std::invalid_argument("File does not exist. Use " + std::string(argv[0]) + " -help for more information.");
            }
          } else {
            throw std::invalid_argument("File not provided. Use " + std::string(argv[0]) + " -help for more information.");
          }
        } else {
          throw std::invalid_argument("Initialization " + std::string(argv[i + 1]) + " not avalaible. Use " + std::string(argv[0]) + " -help for more information.");
        }
        parameters.numberGenerated_ = std::stoi(argv[i + 2]);
      } else {
        throw std::invalid_argument("Initialization not provided. Use " + std::string(argv[0]) + " -help for more information.");
      }
    }
  }

  return parameters;
}