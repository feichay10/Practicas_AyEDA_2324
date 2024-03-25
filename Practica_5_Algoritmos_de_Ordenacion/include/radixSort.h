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
  RadixSort(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

template <typename Key>
RadixSort<Key>::RadixSort(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

template <typename Key>
void RadixSort<Key>::Sort() {
  int max = this->sequence_[0];
  for (int i = 1; i < this->size_; i++) {
    if (this->sequence_[i] > max) {
      max = this->sequence_[i];
    }
  }

  for (int exp = 1; max / exp > 0; exp *= 10) {
    int output[this->size_];
    int count[10] = {0};

    for (int i = 0; i < this->size_; i++) {
      count[(this->sequence_[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }

    for (int i = this->size_ - 1; i >= 0; i--) {
      output[count[(this->sequence_[i] / exp) % 10] - 1] = this->sequence_[i];
      count[(this->sequence_[i] / exp) % 10]--;
    }

    for (int i = 0; i < this->size_; i++) {
      this->sequence_[i] = output[i];
    }
    if (this->trace_) {
      std::cout << "\t\t    ";
      this->print();
    }
  }
}


#endif // RADIXSORT_H