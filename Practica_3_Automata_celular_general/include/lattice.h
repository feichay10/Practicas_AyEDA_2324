/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 3: Autómata celular general
 * @file lattice.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Tiene la responsabilidad de crear y almacenar las células que
 * representan el espacio celular. Como la representación del espacio celular
 * requiere una estructura de datos diferente, según la dimensión del espacio,
 * se delega a las clases derivadas la especificación del atributo. a. A partir
 * de la clase base Lattice se derivan las clases para cada dimensión.
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LATTICE_H
#define LATTICE_H

#include <fstream>
#include <iostream>
#include <vector>

#include "cell.h"
#include "factoryCell.h"

enum borderType { kOpen = 0, kPeriodic = 1, kReflective = 2, kNoBorder = 3 };

class Lattice {
 public:
  Lattice() = default;
  Lattice(const Position& size, const State& state, FactoryCell& factory);
  Lattice(const char* file, FactoryCell& factory);
  virtual ~Lattice();

  virtual void nextGeneration() = 0;
  virtual std::size_t Population() const = 0;

  virtual Cell& operator[](const Position&) const = 0;
  virtual std::ostream& display(std::ostream&) const = 0;
  friend std::ostream& operator<<(std::ostream&, const Lattice&);

 protected:
  virtual void loadInitialConfiguration();

  std::string file_;
  FactoryCell* factoryCell_;
};

class Lattice1D : public Lattice {
 public:
  Lattice1D() = default;
  Lattice1D(const Position& size, const State& state, FactoryCell& factory) {
    size1D_ = size[0] + 2;
    cells_ = new Cell*[size1D_];
    for (int i = 0; i < size1D_; i++) {
      cells_[i] = factory.createCell(PositionDim<1>(i), state);
    }

    loadInitialConfiguration();
  }

  ~Lattice1D() override {
    for (int i = 0; i < size1D_; i++) {
      delete cells_[i];
    }
    delete[] cells_;
  }

  void nextGeneration() {
    for (int i = 1; i < size1D_ - 1; i++) {
      cells_[i]->nextState(*this);
    }
    for (int i = 1; i < size1D_ - 1; i++) {
      cells_[i]->updateState();
    }
  }

  std::size_t Population() const {
    size_t population_ = 0;
    for (int i = 1; i < size1D_ - 1; i++) {
      if (cells_[i]->getState() == kAlive) {
        population_++;
      }
    }
    return population_;
  }

  Cell& operator[](const Position& position) const override {
    return *cells_[position[0]];
  }
  
  std::ostream& display(std::ostream& os) const override {
    for (int i = 1; i < size1D_ - 1; i++) {
      os << *cells_[i];
    }
    return os;
  }

  friend std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
    return lattice.display(os);
  }

 private:
  void loadInitialConfiguration() {

  }

  int size1D_;
  Cell** cells_;
};

class Lattice1D_Open : public Lattice1D {
 public:
  Lattice1D_Open() = default;
  Lattice1D_Open(const Position& size, const State& state, FactoryCell& factory);
  ~Lattice1D_Open() = default;

  Cell& operator[](const Position&) const override;
};

#endif  // LATTICE_H