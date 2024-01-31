/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 1: Autómata celular elemental
 * @file lattice.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LATTICE_H_
#define LATTICE_H_

#pragma once

#include <iostream>
#include <vector>

#include "cell.h"

class Lattice {
 public:
  Lattice(const int&, const int&);
  ~Lattice();
  const Cell& getCell(const Position&) const;
  void nextGeneration();
  friend std::ostream& operator<<(std::ostream&, const Lattice&);

 private:
  std::vector<Cell*> lattice_;
  int width_;
  int height_;
};

#endif  // LATTICE_H_