/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file lattice1D.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/lattice1D.h"

Lattice1D::Lattice1D(int size) {
  size_ = size + 2; // Se añaden dos células para los bordes

  lattice1D_ = new CellACE*[size_];
  for (int i = 0; i < size_; i++) {
    lattice1D_[i] = new CellACE(PositionDim<1, int>(i), kDead);
  }

  loadInitialConfiguration();
}