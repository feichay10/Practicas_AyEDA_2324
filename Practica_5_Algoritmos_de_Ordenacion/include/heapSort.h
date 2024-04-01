/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file heapSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "sortMethod.h"

template <typename Key>
class HeapSort : public SortMethod<Key> {
 public:
  HeapSort(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

template <typename Key>
HeapSort<Key>::HeapSort(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

template <typename Key>
void HeapSort<Key>::Sort() {
  heapSort(this->sequence_, this->size_);
}

#endif  // HEAPSORT_H