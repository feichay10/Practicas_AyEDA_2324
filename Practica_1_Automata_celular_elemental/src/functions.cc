/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Autómata celular elemental
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
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

void checkFile(std::string file) {
  std::ifstream file_config(file);
  if (!file_config.is_open()) {
    throw "The file does not exist.";
    exit(EXIT_FAILURE);
  } else {
    std::string line;
    while (std::getline(file_config, line)) {
      for (int i = 0; i < line.size(); i++) {
        if (line[i] != '0' && line[i] != '1') {
          throw "The file must contain only 0s and 1s.";
          exit(EXIT_FAILURE);
        }
      }
    }
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