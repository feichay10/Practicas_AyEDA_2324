/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Autómata celular elemental
 * @file lattice.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/lattice.h"

Lattice::Lattice(int size, borderType border, openBorderType openBorderType) {
  size_ = size;
  if (border == kOpen) {
  } else {
    cells_ = new Cell[size + 2];
  }
}

Lattice::~Lattice() {

}

Cell& Lattice::getCell(const Position& position) const {

}

int Lattice::getSize() const { 

}

void Lattice::setSize(int size) { 

}

void Lattice::loadInitialConfiguration(std::string file) {
  
}

void Lattice::nextGeneration() {

}

std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {

}