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
  QuickSort(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

template <typename Key>
QuickSort<Key>::QuickSort(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

template <typename Key>
void QuickSort<Key>::Sort() {
  quickSort(this->sequence_, 0, this->size_ - 1);
}

#endif  // QUICKSORT_H