/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file binSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BINSORT_H
#define BINSORT_H

#include "sortMethod.h"

/**
 * @brief Class BinSort that inherits from SortMethod.
 * 
 * @tparam Key 
 */
template <class Key>
class BinSort : public SortMethod<Key> {
 public:
  BinSort(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

/**
 * @brief Construct a new Bin Sort< Key>:: Bin Sort object
 * 
 * @tparam Key 
 * @param sequence 
 * @param size 
 */
template <class Key>
BinSort<Key>::BinSort(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

/**
 * @brief Function that sorts the sequence using the bin sort algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void BinSort<Key>::Sort() {
  binSort(this->sequence_, this->size_, this->trace_);
}

#endif  // BINSORT_H