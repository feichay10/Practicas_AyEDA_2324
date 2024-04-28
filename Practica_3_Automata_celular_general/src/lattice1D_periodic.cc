/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file lattice1D_periodic.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/Lattice/lattice1D_periodic.h"

Lattice1D_Periodic::~Lattice1D_Periodic() {
  for (int i = 0; i < size_; i++) {
    delete lattice_[i];
  }
  delete[] lattice_;
}

Cell& Lattice1D_Periodic::operator[](const Position& position) const {
  if (position[0] < 0) {
    return *lattice_[size_ + position[0]];
  } else if (position[0] >= size_) {
    return *lattice_[position[0] - size_];
  }
  return *lattice_[position[0]];
}