/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 2: El Juego de la Vida
 * @file lattice.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LATTICE_H_
#define LATTICE_H_

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "cell.h"
#include "position.h"

enum borderType { kReflective = 0, kNoBorder = 1 };

class Cell;

class Lattice {
 public:
  // Constructor y destructor
  Lattice(int N, int M);
  Lattice(const char*);
  ~Lattice();

  // Getters y Setters
  int getRows() const;
  int getColumns() const;
  Cell& getCell(const Position& position) const;

  // Métodos de la clase
  void nextGeneration();
  std::size_t Population() const;
  void saveToFile(const std::string& fileOut) const;

  // Sobrecarga de operadores
  Cell& operator[](const Position&);
  friend std::ostream& operator<<(std::ostream& os, const Lattice& lattice);

 private:
  void loadInitialConfiguration(int N, int M);
  void setFrontier();

  int rows_;
  int columns_;
  size_t population_ = 0;
  std::vector<std::vector<Cell*>> lattice_;
};

#endif  // LATTICE_H_