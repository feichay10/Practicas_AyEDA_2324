/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file dfRandom.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DFRANDOM_H
#define DFRANDOM_H

#include <cstdlib>
#include <ctime>

#include "dispersionFunction.h"

template <class Key>
class dfRandom : public DispersionFunction<Key> {
 public:
 public:
  explicit dfRandom(const unsigned tableSize) : tableSize_(tableSize) {}
  unsigned operator()(const Key& k) const override;

 private:
  unsigned tableSize_; 
};

// Basada en pseudoaleatorios, h(k) = {srand(k); rand()}
template <class Key>
unsigned dfRandom<Key>::operator()(const Key& k) const {
  srand(static_cast<unsigned>(k));
  return rand() % tableSize_;
}

#endif  // DFRANDOM_H