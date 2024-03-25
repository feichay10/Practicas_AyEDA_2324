/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file mergeSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MERGESORT_H
#define MERGESORT_H

#include "sortMethod.h"

template <typename Key>
class MergeSort : public SortMethod<Key> {
 public:
  void Sort(StaticSequence<Key>& sequence, int size) override;

 private:
  void mSort(StaticSequence<Key>& sequence, int begin, int end);
  void mix(StaticSequence<Key>& sequence, int begin, int middle, int end);
};

template <typename Key>
void MergeSort<Key>::Sort(StaticSequence<Key>& sequence, int size) {
  mSort(sequence, 0, size - 1);
}

template <typename Key>
void MergeSort<Key>::mSort(StaticSequence<Key>& sequence, int begin, int end) {
  if (begin < end) {
    int middle = (begin + end) / 2;
    mSort(sequence, begin, middle);
    mSort(sequence, middle + 1, end);
    mix(sequence, begin, middle, end);
  }
}

template <typename Key>
void MergeSort<Key>::mix(StaticSequence<Key>& sequence, int begin, int middle, int end) {
  int i = begin;
  int j = middle + 1;
  Key* aux = new Key[end + 1];
  int size = sequence.getSize();
  for (int k = begin; k <= end; k++) {
    if (i <= middle && (j > end || sequence[i] < sequence[j])) {
      aux[k] = sequence[i];
      i++;
    } else {
      aux[k] = sequence[j];
      j++;
    }
  }

  for (int k = begin; k <= end; k++) {
    sequence[k] = aux[k];
  }

  if (this->trace_) {
    std::cout << "\t\t    ";
    this->print(sequence, size);
  }

  delete[] aux;
}

#endif  // MERGESORT_H