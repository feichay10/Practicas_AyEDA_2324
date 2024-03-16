/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file efQuadratic.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef EFQUADRATIC_H
#define EFQUADRATIC_H

#include "explorationFunction.h"

/**
 * @brief Class for implementing quadratic exploration technique
 * 
 * @tparam Key 
 */
template <class Key>
class efQuadratic : public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const override;
};

/**
 * @brief Operator for quadratic exploration
 * 
 * @tparam Key 
 * @param k 
 * @param i 
 * @return unsigned 
 */
template <class Key>
unsigned efQuadratic<Key>::operator()(const Key& k, unsigned i) const {
  return i * i;
}

#endif  // EFQUADRATIC_H