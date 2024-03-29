/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file quickSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "sortMethod.h"

template <typename Key>
class QuickSort : public SortMethod<Key> {
 public:
  QuickSort(StaticSequence<Key>& sequence, int size);
  void Sort() override;

 private:
  void qSort(StaticSequence<Key>& sequence, int begin, int end);
};

template <typename Key>
QuickSort<Key>::QuickSort(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

template <typename Key>
void QuickSort<Key>::Sort() {
  qSort(this->sequence_, 0, this->size_ - 1);
}

template <typename Key>
void QuickSort<Key>::qSort(StaticSequence<Key>& sequence, int begin, int end) {
  int i = begin;
  int j = end;
  Key pivot = sequence[(begin + end) / 2];
  if (this->trace_) {
    std::cout << "Pivot: " << pivot << "\t    ";
  }
  while (i <= j) {
    while (sequence[i] < pivot) i++;
    while (sequence[j] > pivot) j--;
    if (i <= j) {
      this->swap(sequence[i], sequence[j]);
      i++;
      j--;
    }
  }
  if (this->trace_) {
    this->print();
    std::cout << std::endl;
  }
  if (begin < j) qSort(sequence, begin, j);
  if (i < end) qSort(sequence, i, end);
}

#endif  // QUICKSORT_H