/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenacion
 * @file ordenation.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ORDENATION_H
#define ORDENATION_H

#include "sortMethod.h"

// El codigo de los metodos de ordenacion estaran aqui
// Son plantilla de funciones

template <typename Key>
void selection(StaticSequence<Key>& sequence, int size) {
  Key temp;
  for (int i = 0; i < size - 1; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
      if (sequence[j] < sequence[min]) {
        min = j;
      }
    }
    temp = sequence[min];
    sequence[min] = sequence[i];
    sequence[i] = temp;
    if (sequence.getTrace()) {
      sequence.print();
    }
  }
}


#endif // ORDENATION_H