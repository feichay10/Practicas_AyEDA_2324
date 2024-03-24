/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file selection.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SELECTION_H
#define SELECTION_H

#include "sortMethod.h"

template <typename Key>
class Selection : public SortMethod<Key> {
 public:
  void Sort(StaticSequence<Key>& sequence, int size) override;
};

template <typename Key>
void Selection<Key>::Sort(StaticSequence<Key>& sequence, int size) {
  Key temp;
  for (int i = 0; i < size - 1; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
      if (sequence[j] < sequence[min]) {
        min = j;
      }
    }
    this->swap(sequence[min], sequence[i]);
    if (this->getTrace()) {
      this->print(sequence, size);
    }
  }
}

#endif  // SELECTION_H