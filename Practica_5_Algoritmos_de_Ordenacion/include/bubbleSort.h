/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file bubbleSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "sortMethod.h"

/**
 * @brief Class BubbleSort that inherits from SortMethod.
 * 
 * @tparam Key 
 */
template <typename Key>
class BubbleSort : public SortMethod<Key> {
 public:
  BubbleSort(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

/**
 * @brief Construct a new Bubble Sort< Key>:: Bubble Sort object
 * 
 * @tparam Key 
 * @param sequence 
 * @param size 
 */
template <typename Key>
BubbleSort<Key>::BubbleSort(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

/**
 * @brief Function that sorts the sequence using the bubble sort algorithm.
 * 
 * @tparam Key 
 */
template <typename Key>
void BubbleSort<Key>::Sort() {
  bubbleSort(this->sequence_, this->size_, this->trace_);
}

#endif // BUBBLESORT_H