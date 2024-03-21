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
  RadixSort(StaticSequence<Key>& sequence) : SortMethod<Key>{sequence} {}
  void Sort() const override;
};

#endif  // RADIXSORT_H