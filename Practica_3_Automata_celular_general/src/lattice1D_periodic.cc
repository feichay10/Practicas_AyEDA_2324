/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file lattice1D_periodic.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/lattice1D_periodic.h"
#include "../include/positionDim.h"

Lattice1D_Periodic::Lattice1D_Periodic(int& size, const FactoryCell& factory, borderType border) : Lattice1D(size, factory, border) {
  Position* position;
  position = new PositionDim<1>(1, -1);
  borderLattice_ = factory.createCell(*position, kDead);
  lattice_[0] = borderLattice_;
  position = new PositionDim<1>(1, size_);
  borderLattice_ = factory.createCell(*position, kDead);
  lattice_[size_] = borderLattice_;
}

Lattice1D_Periodic::Lattice1D_Periodic(const std::string& fileName, const FactoryCell& factory, borderType border) : Lattice1D(fileName, factory, border) {
  Position* position;
  position = new PositionDim<1>(1, -1);
  borderLattice_ = factory.createCell(*position, kDead);
  lattice_[0] = borderLattice_;
  position = new PositionDim<1>(1, size_);
  borderLattice_ = factory.createCell(*position, kDead);
  lattice_[size_] = borderLattice_;
}

Lattice1D_Periodic::~Lattice1D_Periodic() {
  delete borderLattice_;
}

Cell& Lattice1D_Periodic::operator[](const Position& position) const {
  if (position[0] < 0) {
    return *lattice_[size_ + position[0]];
  } else if (position[0] >= size_) {
    return *lattice_[position[0] - size_];
  }
  return *lattice_[position[0]];
}

