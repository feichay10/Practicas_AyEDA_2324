/**
 * @file functions.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/functions.h"

void checkSize(int size, std::string file) {
  if (size <= 0) {
    std::cerr << "El tamaño del retículo debe ser un número mayor a cero." << std::endl;
    exit(EXIT_FAILURE);
  }

  // if (file.empty()) {
  //   return;
  // }

  int count = 0;
  if (!file.empty()) {
    std::ifstream file_config(file);
    if (file_config.is_open()) {
      std::string line;
      while (std::getline(file_config, line)) {
        count += line.size();
      }
    }
  } else {
    return;
  }

  if (count != size) {
    std::cerr << "El tamaño del retículo no coincide con el tamaño del fichero." << std::endl;
    exit(EXIT_FAILURE);
  }
}

void cellEvolution(Lattice &lattice) {
  std::cout << lattice << std::endl;
  while (true) {
    lattice.nextGeneration();
    std::cout << lattice;
    if (std::cin.get() == 'q') {
      break;
    }
  }
}