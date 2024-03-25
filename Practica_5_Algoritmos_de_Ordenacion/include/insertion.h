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
  void Sort(StaticSequence<Key>& sequence, int size) override;
};

template <typename Key>
void Insertion<Key>::Sort(StaticSequence<Key>& sequence, int size) {

}