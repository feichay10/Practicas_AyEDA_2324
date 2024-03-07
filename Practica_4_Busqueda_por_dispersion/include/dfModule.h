/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file DFModule.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DFMODULE_H
#define DFMODULE_H

#include "dispersionFunction.h"

template <class Key>
class DFModule {
 public:
  explicit DFModule(const unsigned tableSize) : tableSize_(tableSize) {}
  unsigned operator()(const Key &k) const;

 private:
  unsigned tableSize_;
};

template <class Key>
unsigned DFModule<Key>::operator()(const Key &k) const {
  return k % tableSize_;
}

#endif  // DFMODULE_H