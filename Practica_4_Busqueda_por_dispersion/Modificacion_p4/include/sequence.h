/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file sequence.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <fstream>

template <class Key>
class Sequence {
 public:
  virtual bool search(const Key& k) const = 0;
  virtual bool insert(const Key& k) = 0;
  virtual bool insertByFile(std::string file) = 0;
  virtual bool remove(const Key& k) = 0;
  virtual bool clear() = 0;
  virtual bool isFull() const = 0;
  virtual void print() = 0;
};

#endif  // SEQUENCE_H