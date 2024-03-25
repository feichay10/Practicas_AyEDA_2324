/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file radixSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef RADIXSORT_H
#define RADIXSORT_H

#include "sortMethod.h"

template <typename Key>

class RadixSort : public SortMethod<Key> {
 public:
  void Sort(StaticSequence<Key>& sequence, int size) override;
};

template <typename Key>
void RadixSort<Key>::Sort(StaticSequence<Key>& sequence, int size) {
  int max = sequence[0];
  for (int i = 1; i < size; i++) {
    if (sequence[i] > max) {
      max = sequence[i];
    }
  }

  for (int exp = 1; max / exp > 0; exp *= 10) {
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++) {
      count[(sequence[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
      output[count[(sequence[i] / exp) % 10] - 1] = sequence[i];
      count[(sequence[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++) {
      sequence[i] = output[i];
    }
    if (this->trace_) {
      std::cout << "\t\t    ";
      this->print(sequence, size);
    }
  }
}

#endif // RADIXSORT_H