/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file shakeSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SHAKESORT_H
#define SHAKESORT_H

#include "sortMethod.h"

template <typename Key>
class ShakeSort : public SortMethod<Key> {
 public:
  ShakeSort(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

template <typename Key>
ShakeSort<Key>::ShakeSort(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

template <typename Key>
void ShakeSort<Key>::Sort() {
  int start = 1;
  int end = this->size_ - 1;
  int cam = this->size_;
  while (start <= end) {
    for (int i = end; i >= start; i--) {
      if (this->sequence_[i] < this->sequence_[i - 1]) {
        this->swap(this->sequence_[i - 1], this->sequence_[i]);
        cam = i;
      }
      if (this->trace_) {
        std::cout << "\t\t    ";
        this->print();
        std::cout << std::endl;
      }
    }
    start = cam + 1;
    for (int i = start; i <= end; i++) {
      if (this->sequence_[i] < this->sequence_[i - 1]) {
        this->swap(this->sequence_[i - 1], this->sequence_[i]);
        cam = i;
      }
      if (this->trace_) {
        std::cout << "\t\t    ";
        this->print();
        std::cout << std::endl;
      }
    }
    end = cam - 1;
  }
}

#endif  // SHAKESORT_H