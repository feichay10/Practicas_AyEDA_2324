/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 2: El Juego de la Vida
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

void cellEvolution(Lattice &lattice) {
  std::cout << std::endl;
  for (int i = 0; i < 5; i++) {
    lattice.nextGeneration();
    std::cout << lattice;
    std::cout << "Poblacion actual: " << lattice.Population() << std::endl << std::endl;
  }
}