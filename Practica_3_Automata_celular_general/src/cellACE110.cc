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

#include "../include/cellACE110.h"

CellACE110::CellACE110(const PositionDim<1, int>& position, const State state) : CellACE(position, state) {}

void CellACE110::nextState(const Lattice& lattice) {
  // int left = lattice[position_<1, int>() - 1].getState();
  // int center = lattice[position_<1, int>()].getState();
  // int right = lattice[position_<1, int>() + 1].getState();

  // nextState_ = static_cast<State>((center + right + center * right + left * center * right) % 2);
}