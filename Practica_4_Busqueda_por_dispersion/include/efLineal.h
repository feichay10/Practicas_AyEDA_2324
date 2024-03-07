/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file efLineal.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef EFLINEAL_H
#define EFLINEAL_H

#include "explorationFunction.h"

template <typename Key>
class EFLineal : public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& key, unsigned i) const;
};

template <typename Key>
unsigned EFLineal<Key>::operator()(const Key& key, unsigned i) const {
  return i;
}

#endif  // EFLINEAL_H