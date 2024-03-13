/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file cellular_automata.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

#include "../include/cell.h"
#include "../include/cellACE110.h"
#include "../include/cellACE30.h"
#include "../include/lattice.h"
#include "../include/lattice1D.h"
#include "../include/lattice1D_open.h"
#include "../include/lattice1D_periodic.h"
#include "../include/lattice2D.h"
#include "../include/lattice2D_reflective.h"
#include "../include/factoryCell.h"
#include "../include/factoryCellACE110.h"
#include "../include/factoryCellACE30.h"
#include "../include/factoryCellLife23_3.h"
#include "../include/functions.h"

int dim = 1;
int size;
int rows;
int columns;
borderType border;
openBorderType openBorder;
std::string fileIn = "";
std::string fileOut = "";
FactoryCell* factoryCell;
Lattice* lattice;

void checkProgramParameters(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "-help") {
    throw kUsage;
    exit(EXIT_FAILURE);
  } else if (argc == 1) {
    throw std::string("No arguments provided. Use ") + argv[0] +
        " -help for more information.";
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

  bool sizeFlag2 = false, initFlag2 = false;

  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-dim") {
      dim = std::stoi(argv[i + 1]);
    } else if (std::string(argv[i]) == "-size") {
      sizeFlag2 = true;
      size = std::stoi(argv[i + 1]);
      if (dim == 2) {
        rows = size;
        columns = std::stoi(argv[i + 2]);
      }
    } else if (std::string(argv[i]) == "-init") {
      initFlag2 = true;
      fileIn = argv[i + 1];
    } else if (std::string(argv[i]) == "-cell") {
      if (std::string(argv[i + 1]) == "Ace110") {
        factoryCell = new FactoryCellACE110();
      } else if (std::string(argv[i + 1]) == "Ace30") {
        factoryCell = new FactoryCellACE30();
      } else if (std::string(argv[i + 1]) == "Life23_3") {
        factoryCell = new FactoryCellLife23_3();
      }
    } else if (std::string(argv[i]) == "-border") {
      if (std::string(argv[i + 1]) == "open") {
        border = kOpen;
        openBorder = static_cast<openBorderType>(std::stoi(argv[i + 2]));
      } else if (std::string(argv[i + 1]) == "periodic") {
        border = kPeriodic;
      } else if (std::string(argv[i + 1]) == "reflective") {
        border = kReflective;
      } else if (std::string(argv[i + 1]) == "noborder") {
        border = kNoBorder;
      }
    }
  }

  if (sizeFlag2) {
    switch (dim) {
    case 1:
      if (border == kOpen) {
        if (openBorder == kCold) {
          lattice = new Lattice1D_Open(size, *factoryCell, border, kCold);
        } else if (openBorder == kHot) {
          lattice = new Lattice1D_Open(size, *factoryCell, border, kHot);
        }
      } else if (border == kPeriodic) { 
        std::cout << "Borde periodico" << border << std::endl;
        lattice = new Lattice1D_Periodic(size, *factoryCell, border);
      }
      break;
    case 2:
      if (border == kReflective) {
        std::cout << "Borde reflectante" << border << std::endl;
        lattice = new Lattice2D_Reflective(rows, columns, *factoryCell, border);
      } else if (border == kNoBorder) {
        std::cout << "No border" << std::endl;
        // lattice = new Lattice2D(size, size, *factoryCell, border);
      }
      break;
    default:
      throw std::string("Invalid dimension. Use -help for more information.");
      break;
    }
  } else if (initFlag2) {
    switch (dim) {
      case 1:
        if (border == kOpen) {
          if (openBorder == kCold) {
            lattice = new Lattice1D_Open(fileIn, *factoryCell, border, kCold);
          } else if (openBorder == kHot) {
            lattice = new Lattice1D_Open(fileIn, *factoryCell, border, kHot);
          }
        } else if (border == kPeriodic) {
          std::cout << "Borde periodico" << border << std::endl;
          lattice = new Lattice1D_Periodic(fileIn, *factoryCell, border);
        }
        break;
      case 2:
        if (border == kReflective) {
          std::cout << "Borde reflectante" << border << std::endl;
          lattice = new Lattice2D_Reflective(rows, columns, *factoryCell, border);
        } else if (border == kNoBorder) {
          std::cout << "No border" << std::endl;
          // lattice = new Lattice2D(size, size, *factoryCell, border);
        }
        break;
      default:
        throw std::string("Invalid dimension. Use -help for more information.");
        break;
    }
  }

  // std::cout << "Dimension: " << dim << std::endl;
  // std::cout << "Size: " << size << std::endl;
  // std::cout << "Border: " << border << std::endl;
  // std::cout << "Open border: " << openBorder << std::endl;

  std::cout << "\nInitial lattice: " << std::endl;
  std::cout << *lattice << std::endl;

  menu(*lattice);
}

int main(int argc, char* argv[]) {
  try {
    checkProgramParameters(argc, argv);
  } catch (std::string& e) {
    std::cerr << e << std::endl;
  }

  return 0;
}