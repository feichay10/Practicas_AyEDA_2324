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

#include "cell.h"

const std::string kRedBold = "\033[31m\033[1m";
const std::string kGreenBold = "\033[32m\033[1m";
const std::string kPurpleBold = "\033[35m\033[1m";
const std::string kResetText = "\033[0m";

typedef int Position;
enum borderType { kOpen = 0, kPeriodic = 1, kReflector = 2 };
enum openBorderType { kCold = 0, kHot = 1 };

class Cell;

class Lattice {
 public:
  // Constructor y destructor
  Lattice(int size, borderType border, openBorderType openBorderType,
          std::string fileIn, std::string fileOut);
  ~Lattice();

  // Getters y Setters
  Cell& getCell(const Position& position) const;
  int getSize() const;
  
  // Métodos de la clase
  void nextGeneration();

  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Lattice& lattice);

 private:
  void printLatticeInformation(std::string file);
  void loadInitialConfiguration(std::string file);
  void setFrontier();

  Cell** cells_;
  int size_;
  borderType borderType_;
  openBorderType openBorderType_ = kCold;
  std::string initialConfiguration_;
  std::string fileOut_;
};

#endif  // LATTICE_H_