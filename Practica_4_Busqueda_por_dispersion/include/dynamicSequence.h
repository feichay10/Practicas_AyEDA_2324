/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file dynamicSequence.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DYNAMICSEQUENCE_H
#define DYNAMICSEQUENCE_H

#include "sequence.h"

template <class Key>
class DynamicSequence : public Sequence<Key> {
 public:
  DynamicSequence();
  ~DynamicSequence();
  bool search(const Key& k) const;
  bool insert(const Key& k);
  void print() const;

 private:
  Key* data_;
  int size_;
  int capacity_;
};

#endif // DYNAMICSEQUENCE_H