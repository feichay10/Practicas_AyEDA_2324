/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file shellSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "sortMethod.h"

template <typename Key>
class ShellSort : public SortMethod<Key> {
 public:
  void Sort(StaticSequence<Key>& sequence, int size) override;

 private:
  void deltaSort(int delta, StaticSequence<Key>& sequence, int size);
};

template <typename Key>
void ShellSort<Key>::Sort(StaticSequence<Key>& sequence, int size) {
  int delta = size;
  while (delta > 1) {
    delta = delta / 2;
    deltaSort(delta, sequence, size);
  }
}

template <typename Key>
void ShellSort<Key>::deltaSort(int delta, StaticSequence<Key>& sequence, int size) {
  for (int i = delta; i < size; i++) {
    Key temp = sequence[i];
    int j = i;
    while ((j >= delta) && (temp < sequence[j - delta])) {
      sequence[j] = sequence[j - delta];
      j = j - delta;
    }
    sequence[j] = temp;
  }
  if (this->trace_) {
    std::cout << "\t\t    ";
    this->print(sequence, size);
  }
}

#endif  // SHELLSORT_H