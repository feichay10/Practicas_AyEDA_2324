/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file efRedispersion.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef EFREDISPERSION_H
#define EFREDISPERSION_H

#include "dispersionFunction.h"
#include "explorationFunction.h"

template <class Key>
class efRedispersion : public ExplorationFunction<Key> {
 public:
  efRedispersion() {}
  efRedispersion(DispersionFunction<Key>* f) : df_(f) {}
  unsigned operator()(const Key& k, unsigned i) const override;

 private:
  DispersionFunction<Key>* df_;
};

// Redispersión, g(k,i) = f^(i)(k)
// La implementación de la estrategia de exploración por redispersión se utiliza
// el generador de números pseudo-aleatorios. Se inicializa la semilla del
// generador con el valor de la clave, srand(k), y se retorna el valor de la
// i-ésima llamada a rand() como el valor de desplazamiento f^(i)(k).
template <class Key>
unsigned efRedispersion<Key>::operator()(const Key& k, unsigned i) const {
  return df_->operator()(k, i);
}

#endif  // EFREDISPERSION_H