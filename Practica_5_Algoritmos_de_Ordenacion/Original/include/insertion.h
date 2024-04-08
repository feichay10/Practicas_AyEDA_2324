/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file insertion.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef INSERTION_H
#define INSERTION_H

#include "sortMethod.h"

/**
 * @brief Class Insertion that inherits from SortMethod.
 * 
 * @tparam Key 
 */
template <class Key>
class Insertion : public SortMethod<Key> {
 public:
  Insertion(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

/**
 * @brief Construct a new Insertion< Key>:: Insertion object
 * 
 * @tparam Key 
 * @param sequence 
 * @param size 
 */
template <class Key>
Insertion<Key>::Insertion(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

/**
 * @brief Function that sorts the sequence using the insertion sort algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void Insertion<Key>::Sort() {
  insertion(this->sequence_, this->size_, this->trace_);
}

#endif  // INSERTION_H