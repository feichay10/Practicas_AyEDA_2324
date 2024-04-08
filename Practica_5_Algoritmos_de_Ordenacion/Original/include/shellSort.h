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

/**
 * @brief Class ShellSort that inherits from SortMethod.
 * 
 * @tparam Key 
 */
template <class Key>
class ShellSort : public SortMethod<Key> {
 public:
  ShellSort(StaticSequence<Key>& sequence, int size);
  void Sort() override;
};

/**
 * @brief Construct a new Shell Sort< Key>:: Shell Sort object
 * 
 * @tparam Key 
 * @param sequence 
 * @param size 
 */
template <class Key>
ShellSort<Key>::ShellSort(StaticSequence<Key>& sequence, int size) : SortMethod<Key>(sequence, size) {}

/**
 * @brief Function that sorts the sequence using the shell sort algorithm.
 * 
 * @tparam Key 
 */
template <class Key>
void ShellSort<Key>::Sort() {
  shellSort(this->sequence_, this->size_, this->trace_);
}

#endif  // SHELLSORT_H