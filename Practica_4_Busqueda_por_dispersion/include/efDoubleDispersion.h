/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file efDoubleDispersion.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef EFDOUBLEDISPERSION_H
#define EFDOUBLEDISPERSION_H

#include "dispersionFunction.h"
#include "explorationFunction.h"

template <class Key>
class EFDoubleDispersion : public ExplorationFunction<Key> {
 public:
  EFDoubleDispersion() {}
  EFDoubleDispersion(DispersionFunction<Key> *f) : df_(f) {}
  unsigned operator()(const Key &k, unsigned i) const;

 private:
  DispersionFunction<Key> *df_;
};

// Doble dispersión, g(k,i) = f(k) * i
template <class Key>
unsigned EFDoubleDispersion<Key>::operator()(const Key &k, unsigned i) const {
  return df_->operator()(k) * i;
}

#endif  // EFDOUBLEDISPERSION_H