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
 * @date 
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LATTICE_H_
#define LATTICE_H_

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

#include "cell.h"

typedef int Position;
enum borderType { kOpen = 0, kPeriodic = 1 };
enum openBorderType { kCold = 0, kHot = 1 };

class Cell;

class Lattice {
 public:
  // Constructor y destructor
  Lattice(int size, borderType border, openBorderType openBorderType, std::string file);
  ~Lattice();

  // Getters y Setters
  Cell& getCell(const Position& position) const;
  int getSize() const;
  void setSize(int size);
  borderType getBorderType();
  void setBorderType(borderType borderType);

  // Métodos de la clase
  void nextGeneration();

  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Lattice& lattice);

 private:
  // Métodos de la clase privados
  void printLatticeInformation(std::string file);
  void loadInitialConfiguration(std::string file);
  void setFrontier();

  Cell* cells_;
  int size_;
  borderType borderType_;
  openBorderType openBorderType_ = kCold;
  std::string initialConfiguration_;
};

#endif  // LATTICE_H_