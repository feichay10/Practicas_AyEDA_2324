/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file sortMethod.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SORTMETHOD_H
#define SORTMETHOD_H

#include "staticSequence.h"
#include "ordenation.h"

/**
 * @brief Class SortMethod that represents a sorting method.
 * 
 * @tparam Key 
 */
template <class Key>
class SortMethod {
 public:
  SortMethod(StaticSequence<Key>& sequence, int size);
  void setTrace(bool trace);
  virtual void Sort() = 0;
  int getCountComparation();

 protected:
  StaticSequence<Key>& sequence_;
  int size_;
  bool trace_ = false;
  int countComparation = 0;
};

/**
 * @brief Construct a new Sort Method< Key>:: Sort Method object
 * 
 * @tparam Key 
 * @param sequence 
 * @param size 
 */
template <class Key>
SortMethod<Key>::SortMethod(StaticSequence<Key>& sequence, int size) : sequence_(sequence), size_(size) {}

/**
 * @brief Function that sets the trace of the sorting method.
 * 
 * @tparam Key 
 * @param trace 
 */
template <class Key>
void SortMethod<Key>::setTrace(bool trace) {
  trace_ = trace;
}

/**
 * @brief Function that returns the number of comparisons. Modification
 * 
 * @tparam Key 
 * @return int 
 */
template <class Key>
int SortMethod<Key>::getCountComparation() {
  return countComparation;
}

#endif  // SORTMETHOD_H