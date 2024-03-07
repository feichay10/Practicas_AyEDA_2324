/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file lattice2D_reflective.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LATTICE2D_REFLECTIVE_H
#define LATTICE2D_REFLECTIVE_H

#include <iostream>

#include "lattice2D.h"

class Lattice2D_Reflective : public Lattice2D   {
 public:
  Lattice2D_Reflective(int& rows, int& columns, const FactoryCell& factory, borderType border);
  // Lattice2D_Reflective(const std::string& fileName, const FactoryCell& factory, borderType border);
  ~Lattice2D_Reflective();
  Cell& operator[](const Position& position) const override;

 private:
  Cell* borderLattice_;
};

#endif  // LATTICE2D_REFLECTIVE_H