/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file selection.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SELECTION_H
#define SELECTION_H

#include "sortMethod.h"

/**
 * @brief Class Selection that inherits from SortMethod.
 * 
 * @tparam Key 
 */
template <class Key>
class Selection : public SortMethod<Key> {
 public:
  Selection(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

/**
 * @brief Construct a new Selection< Key>:: Selection object
 * 
 * @tparam Key 
 * @param sequence 
 * @param size 
 */
template <class Key>
Selection<Key>::Selection(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

/**
 * @brief Function that sorts the sequence using the selection sort algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void Selection<Key>::Sort() {
  selection(this->sequence_, this->size_, this->trace_);
}


#endif  // SELECTION_H