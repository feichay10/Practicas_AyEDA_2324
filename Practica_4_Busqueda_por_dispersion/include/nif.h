/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file nif.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NIF_H
#define NIF_H

#include <ctime>
#include <iostream>

class Nif {
 public:
  Nif() { 
    srand(time(NULL));
    nif_ = rand() % 100000000;
   }
  Nif(const long nif) { nif_ = nif; }
  bool operator==(const Nif& other) const { return nif_ == other.nif_; }
  bool operator!=(const Nif& other) const { return !(*this == other); }
  operator long() { return nif_; }
  operator unsigned int() const { return nif_; }

  unsigned int operator%(unsigned int m) const { return nif_ % m; }
  long size() const { return 9; }

 private:
  long nif_;
};

#endif  // NIF_H