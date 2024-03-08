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

#include <iostream>

#include "key.h"

class Nif : public Key<long> {
 public:
  Nif();
  Nif(long nif);
  ~Nif() = default;

  bool operator<(const Nif& other) const;
  bool operator>(const Nif& other) const;
  bool operator<=(const Nif& other) const;
  bool operator>=(const Nif& other) const;
  bool operator==(const Nif& other) const;
  long operator/(const Nif& other) const;
  friend std::istream& operator>>(std::istream& is, Nif& nif) {
    is >> nif.key_;
    return is;
  }

  friend std::ostream& operator<<(std::ostream& os, const Nif& nif) {
    os << nif.key_;
    return os;
  }

  operator long();

 private:
  long key_;
};

Nif::Nif() {
  srand(time(nullptr));
  key_ = rand() % 100000000; 
}

Nif::Nif(long nif) {
  key_ = nif;
}

bool Nif::operator<(const Nif& other) const {
  return key_ < other.key_;
}

bool Nif::operator>(const Nif& other) const {
  return key_ > other.key_;
}

bool Nif::operator<=(const Nif& other) const {
  return key_ <= other.key_;
}

bool Nif::operator>=(const Nif& other) const {
  return key_ >= other.key_;
}

bool Nif::operator==(const Nif& other) const {
  return key_ == other.key_;
}

long Nif::operator/(const Nif& other) const {
  return key_ / other.key_;
}

Nif::operator long() {
  return key_;
}

#endif  // NIF_H