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

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "cell.h"

typedef int Position;

class Cell;

class Lattice {
 public:
  // Constructor y destructor
  Lattice(int size);
  ~Lattice();

  // Getters y Setters
  Cell& getCell(const Position& position) const;
  int getSize() const;
  void setSize(int size);

  // Métodos de la clase
  void loadInitialConfiguration(std::string file);
  void nextGeneration();

  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Lattice& lattice);

 private:
  Cell* cells_;
  int size_;
};

#endif  // LATTICE_H_