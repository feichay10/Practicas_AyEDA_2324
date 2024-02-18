/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Autómata celular elemental
 * @file cellular_automaton.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <fstream>
#include <iostream>
#include <string>

#include "../include/cell.h"
#include "../include/functions.h"
#include "../include/lattice.h"

int size;
borderType borderTypeVar;
openBorderType openBorderTypeVar = kCold;
std::string fileIn = "";
std::string fileOut = "";

void checkProgramParameters(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "-help") {
    throw kUsage;
    exit(EXIT_FAILURE);
  } else if (argc == 1) {
    throw std::string("No arguments provided. Use ") + argv[0] + " -help for more information.";
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-size") {
      if (i + 1 < argc) {
        size = std::stoi(argv[i + 1]);
      } else {
        throw std::string("Missing lattice size.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-border") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) == "open") {
          borderTypeVar = kOpen;
          if (i + 2 < argc) {
            if (std::string(argv[i + 2]) == "0") {
              openBorderTypeVar = kCold;
            } else if (std::string(argv[i + 2]) == "1") {
              openBorderTypeVar = kHot;
            } else {
                throw std::string("The value of the open border is not valid.");
              exit(EXIT_FAILURE);
            }
          } else {
            throw std::string("Missing value for open border.");
            exit(EXIT_FAILURE);
          }
        } else if (std::string(argv[i + 1]) == "periodic") {
          borderTypeVar = kPeriodic;
        } else if (std::string(argv[i + 1]) == "reflector") {
          borderTypeVar = kReflector;
        } else {
          throw std::string("The border type is not valid.");
          exit(EXIT_FAILURE);
        }
      } else {
        throw std::string("Missing border type.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-init") {
      if (i + 1 < argc) {
        fileIn = argv[i + 1];
        checkFile(fileIn);
      } else {
        throw std::string("Missing file name.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-output") {
      if (i + 1 < argc) {
        fileOut = argv[i + 1];
      } else {
        throw std::string("Missing file name.");
        exit(EXIT_FAILURE);
      }
    }
  }

  checkSize(size, fileIn);
}

int main(int argc, char* argv[]) {
  try {
    checkProgramParameters(argc, argv);
    Lattice lattice(size, borderTypeVar, openBorderTypeVar, fileIn, fileOut);
    if (!fileOut.empty()) {
      cellEvolutionOnFile(lattice, fileOut);
    } else {
      cellEvolution(lattice);
    }
  } catch (const char* message) {
    std::cerr << message << std::endl;
  } catch (std::string message) {
    std::cerr << message << std::endl;
  }

  return 0;
}