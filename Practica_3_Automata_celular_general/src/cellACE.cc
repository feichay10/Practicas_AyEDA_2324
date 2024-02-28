/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file cellACE.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/cellACE.h"

CellACE::CellACE(const Position& position, const State state) : Cell(position, state) {}

void CellACE::nextState(const Lattice& lattice) {
  int left = lattice.getCell(position_ - 1).getState();
  int right = lattice.getCell(position_ + 1).getState();
  int center = lattice.getCell(position_).getState();

  nextState_ = static_cast<State>((center + right + center * right + left * center * right) % 2);
}