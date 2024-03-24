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
  void Sort(StaticSequence<Key>& sequence, int size) override;

 private:
  void qSort(StaticSequence<Key>& sequence, int begin, int end);
};

template <typename Key>
void QuickSort<Key>::Sort(StaticSequence<Key>& sequence, int size) {
  qSort(sequence, 0, size - 1);
}

template <typename Key>
void QuickSort<Key>::qSort(StaticSequence<Key>& sequence, int begin, int end) {
  int i = begin;
  int f = end;
  int size =  sequence.getSize();
  Key pivot = sequence[(begin + end) / 2];
  std::cout << "Pivot: " << pivot << "\t    ";
  while (i <= f) {
    while (sequence[i] < pivot) i++;
    while (sequence[f] > pivot) f--;
    if (i <= f) {
      this->swap(sequence[i], sequence[f]);
      i++;
      f--;
    }
  }
  if (this->trace_) {
    this->print(sequence, size);
  }
  if (begin < f) qSort(sequence, begin, f);
  if (i < end) qSort(sequence, i, end);
}

#endif  // QUICKSORT_H