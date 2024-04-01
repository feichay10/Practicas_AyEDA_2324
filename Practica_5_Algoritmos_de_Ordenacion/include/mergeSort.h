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

// Print like this:
// Secuencia: [44    55    12    42    94    18    06    67]
// División:  [44    55    12    42]    [94    18    06    67]
// División:  [44    55]    [12    42]    [94    18    06    67]
// División:  [44]    [55]    [12    42]    [94    18    06    67]
// Mezclado:  [44    55]    [12    42]    [94    18    06    67]
// División:  [44    55]    [12]    [42]    [94    18    06    67]
// Mezclado:  [44    55]    [12    42]    [94    18    06    67]
// Mezclado:  [12    42    44    55]    [94    18    06    67]
// División:  [12    42    44    55]    [94    18]    [06    67]
// División:  [12    42    44    55]    [94]    [18]    [06    67]
// Mezclado:  [12    42    44    55]    [18    94]    [06    67]
// División:  [12    42    44    55]    [18    94]    [06]    [67]
// Mezclado:  [12    42    44    55]    [18    94]    [06    67]
// Mezclado:  [12    42    44    55]   [06    18    67    94]
// Mezclado:  [06    12    18    42    44    55    67    94]

template <typename Key>
class MergeSort : public SortMethod<Key> {
 public:
  MergeSort(StaticSequence<Key>& sequence, int size);
  void Sort() override;

 private:
  void mSort(StaticSequence<Key>& sequence, int begin, int end);
  void mix(StaticSequence<Key>& sequence, int begin, int middle, int end);
};

template <typename Key>
MergeSort<Key>::MergeSort(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

template <typename Key>
void MergeSort<Key>::Sort() {
  mSort(this->sequence_, 0, this->size_ - 1);
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
  StaticSequence<Key> temp(end + 1);

  for (int k = begin; k <= end; k++) {
    if (i <= middle && (j > end || sequence[i] <= sequence[j])) {
      temp[k] = sequence[i];
      i++;
    } else {
      temp[k] = sequence[j];
      j++;
    }
  }

  for (int k = begin; k <= end; k++) {
    sequence[k] = temp[k];
  }

  if (this->trace_) {
    std::cout << "\t\t    ";
    this->print();
  }
}

#endif  // MERGESORT_H