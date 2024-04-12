/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file dfModule.h
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

/**
 * @brief Class that represents the module dispersion function
 * 
 * @tparam Key 
 */
template <class Key>
class dfModule : public DispersionFunction<Key> {
 public:
  explicit dfModule(const unsigned tableSize) : tableSize_(tableSize) {}
  unsigned operator()(const Key &k) const override;

 private:
  unsigned tableSize_;
};

/**
 * @brief Operator that returns the module of the key
 * 
 * @tparam Key 
 * @param k 
 * @return unsigned 
 */

//En las funciones de dispersión se debería convertir el objeto Key a long y operar con el long
template <class Key>
unsigned dfModule<Key>::operator()(const Key &k) const {
  // return k % tableSize_;
  return static_cast<long>(k) % tableSize_;
}

#endif  // DFMODULE_H