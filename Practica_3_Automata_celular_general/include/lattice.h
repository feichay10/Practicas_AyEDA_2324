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
  // El lattice dispone de un constructor que inicializa todas la celulas a un
  // estado por defecto, y luego solicitara por teclado la posicion de las
  // celulas que deben tener otro valor de estado en la configuracion inicial
  Lattice() {
  }
  Lattice(const char* file, FactoryCell& factory) {
    file_ = file;
    factoryCell_ = &factory;
  }
  virtual ~Lattice();

  virtual void nextGeneration() = 0;
  virtual std::size_t Population() const = 0;

  virtual Cell& operator[](const Position&) const = 0;
  virtual std::ostream& display(std::ostream&) const = 0;
  friend std::ostream& operator<<(std::ostream&, const Lattice&);

 protected:
  std::string file_;
  FactoryCell* factoryCell_;
};

#endif  // LATTICE_H