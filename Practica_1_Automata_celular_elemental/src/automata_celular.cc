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

#include <cstdlib>
#include <cstring>
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
    throw std::string("Opción no válida. Use ") + argv[0] +
        " -help para más información.";
    exit(EXIT_FAILURE);
  } else if (argc == 1) {
    throw std::string("No se han introducido argumentos. Use ") + argv[0] +
        " -help para más información.";
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-size") {
      size = std::stoi(argv[i + 1]);
    } else if (strcmp(argv[i], "-border") == 0 && i + 2 < argc) {
      if (strcmp(argv[i + 1], "open") == 0) {
        borderTypeVar = kOpen;
        openBorderTypeVar = static_cast<openBorderType>(atoi(argv[i + 2]));
        if (openBorderTypeVar != kCold && openBorderTypeVar != kHot) {
          throw std::string("Opción de frontera abiera no válida. Use ") + argv[0] + " --help para más información.";
        }
        i += 2;  // saltamos los próximos dos argumentos
      } else if (strcmp(argv[i + 1], "periodic") == 0) {
        borderTypeVar = kPeriodic;
        i += 1;  // saltamos el próximo argumento
      } else if (std::string(argv[i + 2]) != "0" && std::string(argv[i + 2]) != "1") {
        throw std::string("Opción de frontera no válida. Use ") + argv[0] + " --help para más información.";
      }
    } else if (std::string(argv[i]) == "-init") {
      file = argv[i + 1];
      checkFile(file);
    }
  }
}

int main(int argc, char* argv[]) {
  try {
    checkProgramParameters(argc, argv);
    checkSize(size, file);
    Lattice lattice(size, borderTypeVar, openBorderTypeVar, file);
    cellEvolution(lattice);
  } catch (const char* message) {
    std::cerr << message << std::endl;
  } catch (std::string message) {
    std::cerr << message << std::endl;
  }

  return 0;
}