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

/**
 * TODO: Ejecucion basica y obligatoria del size
 * TODO: Generar una opcion por defecto si se introduce por tamaño
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
std::string file = "";

void checkProgramParameters(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "-help") {
    throw kUsage;
    exit(EXIT_FAILURE);
  } else if (argc == 2 && std::string(argv[1]) != "-help") {
    throw std::string("Opción no válida. Use ") + argv[0] + " -help para más información.";
    exit(EXIT_FAILURE);
  } else if (argc == 1) {
    throw std::string("No se han introducido argumentos. Use ") + argv[0] + " -help para más información.";
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-size") {
      if (i + 1 < argc) {
        size = std::stoi(argv[i + 1]);
        if (size < 0) {
          throw std::string("El tamaño del retículo no puede ser negativo.");
          exit(EXIT_FAILURE);
        }
      } else {
        throw std::string("Falta el tamaño del retículo.");
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
              throw std::string("El valor de la frontera abierta no es válido.");
              exit(EXIT_FAILURE);
            }
          } else {
            throw std::string("Falta el valor de la frontera abierta.");
            exit(EXIT_FAILURE);
          }
        } else if (std::string(argv[i + 1]) == "periodic") {
          borderTypeVar = kPeriodic;
        } else {
          throw std::string("El tipo de frontera no es válido.");
          exit(EXIT_FAILURE);
        }
      } else {
        throw std::string("Falta el tipo de frontera.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-init") {
      if (i + 1 < argc) {
        file = argv[i + 1];
        checkFile(file);
      } else {
        throw std::string("Falta el nombre del fichero.");
        exit(EXIT_FAILURE);
      }
    }
  }

  checkSize(size, file);
}

int main(int argc, char* argv[]) {
  try {
    checkProgramParameters(argc, argv);
    Lattice lattice(size, borderTypeVar, openBorderTypeVar, file);
    cellEvolution(lattice);
  } catch (const char* message) {
    std::cerr << message << std::endl;
  } catch (std::string message) {
    std::cerr << message << std::endl;
  }

  return 0;
}