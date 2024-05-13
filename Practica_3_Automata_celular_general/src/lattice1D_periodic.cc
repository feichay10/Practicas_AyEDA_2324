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

Lattice1D_Periodic::Lattice1D_Periodic(int& size, FactoryCell*& factory) : Lattice1D(size, factory) {
  lattice_[0]->setState(lattice_[size_ - 2]->getState());
  lattice_[size_ - 1]->setState(lattice_[1]->getState());
}

Lattice1D_Periodic::Lattice1D_Periodic(std::string& fileName, FactoryCell*& factory) : Lattice1D(fileName, factory) {
  lattice_[0]->setState(lattice_[size_ - 2]->getState());
  lattice_[size_ - 1]->setState(lattice_[1]->getState());
}

Lattice1D_Periodic::~Lattice1D_Periodic() {
  delete lattice_[0];
  delete lattice_[size_ - 1];
}

Cell& Lattice1D_Periodic::operator[](const Position& position) const {
  if (position[0] < 0) {
    return *lattice_[size_ + position[0]];
  } else if (position[0] >= size_) {
    return *lattice_[position[0] - size_];
  }
  return *lattice_[position[0]];
}