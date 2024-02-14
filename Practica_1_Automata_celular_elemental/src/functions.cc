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
    throw "The lattice size must be a number greater than zero.";
    exit(EXIT_FAILURE);
  }

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
    throw "The lattice size does not match the file size.";
    exit(EXIT_FAILURE);
  }
}

void cellEvolution(Lattice &lattice) {
  std::cout << "\nUse 'q' to end the cell evolution" << std::endl << std::endl;
  std::cout << lattice << std::endl;
  while (true) {
    lattice.nextGeneration();
    std::cout << lattice;
    if (std::cin.get() == 'q') {
      break;
    }
  }
}