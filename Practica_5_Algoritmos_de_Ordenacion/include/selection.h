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
// #include "staticSequence.h"
// #include "sequence.h"

template <typename Key>
class Selection : public SortMethod<Key> {
 public:
  void Sort(StaticSequence<Key>& sequence) const;
};

template <typename Key>
void Selection<Key>::Sort(StaticSequence<Key>& sequence) const {
  std::cout << "\nSelection sort" << std::endl;

  Key temp;
  for (int i = 0; i < sequence.getSize() - 1; i++) {
    int min = i;
    for (int j = i + 1; j < sequence.getSize(); j++) {
      if (sequence[j] < sequence[min]) {
        min = j;
      }
    } 
    
    temp = sequence[min];
    sequence[min] = sequence[i];
    sequence[i] = temp;
    std::cout << "sequence[i]: " << sequence[i] << std::endl;
  }

  sequence.print();
}

#endif  // SELECTION_H