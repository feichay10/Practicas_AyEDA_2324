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

template <typename Key>
class BubbleSort : public SortMethod<Key> {
 public:
  BubbleSort(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

template <typename Key>
BubbleSort<Key>::BubbleSort(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

template <typename Key>
void BubbleSort<Key>::Sort() {
  for (int i = 0; i < this->size_ - 1; i++) {
    for (int j = 0; j < this->size_ - i - 1; j++) {
      if (this->sequence_[j] > this->sequence_[j + 1]) {
        std::swap(this->sequence_[j], this->sequence_[j + 1]);
      }
    }
    if (this->trace_) {
      std::cout << "\t\t    ";
      this->print();
      std::cout << std::endl;
    }
  }
}

#endif // BUBBLESORT_H