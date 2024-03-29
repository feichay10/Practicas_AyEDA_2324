/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file insertion.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef INSERTION_H
#define INSERTION_H

#include "sortMethod.h"

template <typename Key>
class Insertion : public SortMethod<Key> {
 public:
  Insertion(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

template <typename Key>
Insertion<Key>::Insertion(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

template <typename Key>
void Insertion<Key>::Sort() {
  for (int i = 1; i < this->size_; i++) {
    Key temp = this->sequence_[i];
    int j = i - 1;
    while ((j >= 0) && (this->sequence_[j] > temp)) {
      this->sequence_[j + 1] = this->sequence_[j];
      j--;
    }
    this->sequence_[j + 1] = temp;
    if (this->trace_) {
      std::cout << "\ti = " << i;
      std::cout << "\t    "; 
      this->print();
      std::cout << "\tj = " << j + 1;
      std::cout << std::endl;
    }
  }
}

#endif  // INSERTION_H