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
#include "../include/key.h"
#include "../include/nif.h"

typedef Nif KeyType;

// a. -ts <s>, s es el tamaño de la tabla.
// b. -fd <f>, f es el código que identifica a una función de dispersión.
// c. -hash <open|close>, indica la técnica de dispersión a utilizar. Implica el tipo de
// secuencia utilizada para el parámetro Container.
// d. -bs <s>, s es el tamaño del bloque. Sólo para dispersión cerrada.
// e. -fe <f>, f es el código que identifica a una función de exploración. Sólo para
// dispersión cerrada

int tableSize = 0;
std::string df = "module";
std::string dispersionTechnic = "open";
int blockSize = 0;
std::string ef = "lineal";

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
    if (std::string(argv[i]) == "-ts") {
      if (i + 1 < argc) {
        if (std::stoi(argv[i + 1]) < 1) {
          throw std::string("Invalid table size. Table size must be greater than 0.");
          exit(EXIT_FAILURE);
        } else {
          tableSize = std::stoi(argv[i + 1]);
        }
      } else {
        throw std::string("Table size not provided.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-fd") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) != "module" && std::string(argv[i + 1]) != "sum" && std::string(argv[i + 1]) != "random") {
          throw std::string("Invalid dispersion function. Use random or sum.");
          exit(EXIT_FAILURE);
        } else {
          df = std::string(argv[i + 1]);
        }
      } else {
        throw std::string("Dispersion function not provided.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-hash") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) != "open" && std::string(argv[i + 1]) != "close") {
          throw std::string("Invalid dispersion technic. Use open or closed.");
          exit(EXIT_FAILURE);
        } else {
          dispersionTechnic = std::string(argv[i + 1]);
        }
      } else {
        throw std::string("Dispersion technic not provided.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string (argv[i]) == "-fe") {
      if (i + 1 < argc) {
        if (std::string(argv[i + 1]) != "lineal" && std::string(argv[i + 1]) != "quadratic" && std::string(argv[i + 1]) != "double" && std::string(argv[i + 1]) != "redispersion") {
          throw std::string("Invalid exploration function. Use lineal, quadratic, double or redispersion.");
          exit(EXIT_FAILURE);
        } else {
          ef = std::string(argv[i + 1]);
        }
      } else {
        throw std::string("Exploration function not provided.");
        exit(EXIT_FAILURE);
      }
    }
  }

  std::cout << "Table size: " << tableSize << std::endl;
  std::cout << "Dispersion function: " << df << std::endl;
  std::cout << "Dispersion technic: " << dispersionTechnic << std::endl;
  std::cout << "Block size: " << blockSize << std::endl;
  std::cout << "Exploration function: " << ef << std::endl;

  setParameters(tableSize, df, dispersionTechnic, blockSize, ef);
}

int main(int argc, char* argv[]) {
  try {
    checkProgramParameters(argc, argv);
  } catch (std::string& e) {
    std::cerr << kRedBold << "Error: " << e << kReset << std::endl;
    exit(EXIT_FAILURE);
  }
}