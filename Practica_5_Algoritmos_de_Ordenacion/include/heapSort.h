/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file heapSort.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "sortMethod.h"

template <typename Key>
class HeapSort : public SortMethod<Key> {
 public:
  HeapSort(StaticSequence<Key>& sequence) : SortMethod<Key>{sequence} {}
  void Sort() const override;
};

#endif  // HEAPSORT_H