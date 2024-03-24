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
  void Sort(StaticSequence<Key>& sequence, int size) override;

 private:
  void heapify(StaticSequence<Key>& sequence, int size, int i);
};

template <typename Key>
void HeapSort<Key>::Sort(StaticSequence<Key>& sequence, int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(sequence, size, i);
  }

  for (int i = size - 1; i > 0; i--) {
    this->swap(sequence[0], sequence[i]);
    heapify(sequence, i, 0);
  }
}

template <typename Key>
void HeapSort<Key>::heapify(StaticSequence<Key>& sequence, int size, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < size && sequence[left] > sequence[largest]) {
    largest = left;
  }

  if (right < size && sequence[right] > sequence[largest]) {
    largest = right;
  }

  if (largest != i) {
    this->swap(sequence[i], sequence[largest]);
    heapify(sequence, size, largest);
  }
}

#endif  // HEAPSORT_H