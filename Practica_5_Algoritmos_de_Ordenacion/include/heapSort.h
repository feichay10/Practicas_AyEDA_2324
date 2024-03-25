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
  void downHeap(int i, StaticSequence<Key>& sequence, int size);
};

template <typename Key>
void HeapSort<Key>::Sort(StaticSequence<Key>& sequence, int size) {
  for (int i = size / 2; i >= 0; i--) {
    downHeap(i, sequence, size - 1);
  }
  for (int i = size - 1; i > 0; i--) {
    this->swap(sequence[0], sequence[i]);
    downHeap(0, sequence, i - 1);
  }

  // for (int i = size / 2; i > 0; i--) {
  //   downHeap(i, sequence, size);
  // }
  // for (int i = size; i > 1; i--) {
  //   this->swap(sequence[1], sequence[i]);
  //   downHeap(1, sequence, i - 1);
  // }
}

template <typename Key>
void HeapSort<Key>::downHeap(int i, StaticSequence<Key>& sequence, int size) {
  int h1, h2, h;
  while (2 * i <= size) {
    h1 = 2 * i;
    h2 = h1 + 1;
    if (h1 == size) {
      h = h1;
    } else if (sequence[h1] > sequence[h2]) {
      h = h1;
    } else {
      h = h2;
    }
    if (sequence[h] <= sequence[i]) {
      break;
    } else {
      this->swap(sequence[i], sequence[h]);
      i = h;
    }
  }
}

#endif  // HEAPSORT_H