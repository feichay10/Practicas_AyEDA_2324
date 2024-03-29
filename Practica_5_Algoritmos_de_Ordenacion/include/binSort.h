/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file binSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BINSORT_H
#define BINSORT_H

#include "sortMethod.h"

template <typename Key>
class BinSort : public SortMethod<Key> {
 public:
  BinSort(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

template <typename Key>
BinSort<Key>::BinSort(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

template <typename Key>
void BinSort<Key>::Sort() {
  for (int i = 1; i < this->size_; i++) {
    int j = i;
    Key temp = this->sequence_[i];
    int start = 0;
    int end = i - 1;
    while (start <= end) {
      int middle = (start + end) / 2;
      if (this->sequence_[middle] < temp) {
        start = middle + 1;
      } else {
        end = middle - 1;
      }
    }
    for (int k = i - 1; k >= start; k--) {
      this->sequence_[k + 1] = this->sequence_[k];
    }
    this->sequence_[start] = temp;
    if (this->trace_) {
      std::cout << "\t\t    "; 
      this->print();
      std::cout << std::endl;
    }
  }
}

#endif  // BINSORT_H