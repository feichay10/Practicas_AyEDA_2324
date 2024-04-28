/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file lattice1D_open.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/Lattice/lattice1D_open.h"

Lattice1D_Open::Lattice1D_Open(int& size, FactoryCell*& factory, const openBorderType& borderType) : Lattice1D(size, factory), borderType_(borderType) {
  Position* position;
  if (borderType_ == kCold) {
    position = new PositionDim<1>(1, -1);
    borderLattice_ = factory->createCell(*position, kDead);
  } else {
    position = new PositionDim<1>(1, -1);
    borderLattice_ = factory->createCell(*position, kAlive);
  }
  lattice_[0] = borderLattice_;
  lattice_[size_ - 1] = borderLattice_;
}

Lattice1D_Open::Lattice1D_Open(std::string& fileName, FactoryCell*& factory, const openBorderType& borderType) : Lattice1D(fileName, factory), borderType_(borderType) {
  Position* position;
  if (borderType_ == kCold) {
    position = new PositionDim<1>(1, -1);
    borderLattice_ = factory->createCell(*position, kDead);
  } else {
    position = new PositionDim<1>(1, -1);
    borderLattice_ = factory->createCell(*position, kAlive);
  }
  lattice_[0] = borderLattice_;
  lattice_[size_ - 1] = borderLattice_;
}

Lattice1D_Open::~Lattice1D_Open() {
  delete borderLattice_;
}

Cell& Lattice1D_Open::operator[](const Position& position) const {
  if (position[0] == 0) {
    return *lattice_[0];
  } else if (position[0] == size_ - 1) {
    return *lattice_[size_ - 1];
  } else {
    return *lattice_[position[0]];
  }
}