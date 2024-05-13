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

#include "../include/Cell/cellACE.h"

CellACE::CellACE(Position& position, const State& state) : Cell(position, state) {}

void CellACE::updateState() {
    state_ = nextState_;
  }

std::ostream& CellACE::display(std::ostream& os) {
    os << (state_ == kDead ? "-" : "X");
    return os;
  }