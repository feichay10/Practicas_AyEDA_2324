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

int rows = 0, columns = 0;
borderType borderTypeVar = kNoBorder;
std::string fileIn = "";

void checkProgramParameters(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "-help") {
    throw kUsage;
    exit(EXIT_FAILURE);
  } else if (argc == 1) {
    throw std::string("No arguments provided. Use ") + argv[0] + " -help for more information.";
    exit(EXIT_FAILURE);
  }

  int sizeFlag = 0, initFlag = 0;

  // Si se inicializa los parametros -size e -init a la vez da error
  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-size") {
      sizeFlag++;
    } else if (std::string(argv[i]) == "-init") {
      initFlag++;
    }
  }

  if (sizeFlag == 1 && initFlag == 1) {
    throw std::string("Error: Cannot initialize both -size and -init at the same time.");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-size") {
      if (i + 2 < argc) {
        if (std::stoi(argv[i + 1]) <= 0 || std::stoi(argv[i + 2]) <= 0) {
          throw std::string("Error: The lattice size must be greater than 0.");
          exit(EXIT_FAILURE);
        }
        rows = std::stoi(argv[i + 1]);
        columns = std::stoi(argv[i + 2]);
        i += 3;
        Lattice lattice(rows, columns);
        setBorder(argv[i + 1], borderTypeVar, lattice);
        menu(lattice);
      } else {
        throw std::string("Missing lattice size.");
        exit(EXIT_FAILURE);
      }
    } else if (std::string(argv[i]) == "-init") {
      if (i + 1 < argc) {
        fileIn = argv[i + 1];
        i += 2;
        checkFile(fileIn);        
        Lattice lattice(fileIn.c_str());
        setBorder(argv[i + 1], borderTypeVar, lattice);
        menu(lattice);
      } else {
        throw std::string("Missing file name.");
        exit(EXIT_FAILURE);
      }
    } else {
      throw std::string("Invalid argument: ") + argv[i];
      exit(EXIT_FAILURE);
    }
  }
}

int main(int argc, char* argv[]) {
  try {
    checkProgramParameters(argc, argv);
  } catch (std::string& e) {
    std::cerr << e << std::endl;
    exit(EXIT_FAILURE);
  } catch (int e) {
    std::cerr << kUsage << std::endl;
    exit(EXIT_FAILURE);
  }

  return 0;
}