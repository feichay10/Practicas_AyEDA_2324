/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file hashTable.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

#include "dynamicSequence.h"
#include "sequence.h"
#include "staticSequence.h"
#include "dispersionFunction.h"
#include "explorationFunction.h"

template <class Key, class Container = StaticSequence<Key> >
class HashTable {
 public:
  HashTable(unsigned tableSize, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe, unsigned blockSize);
  ~HashTable();

  bool search(const Key& k) const;
  bool insert(const Key& k);

  std::ostream& operator<<(std::ostream& os) const {

  }

 private:
  unsigned tableSize_;
  Container** table_;
  DispersionFunction<Key>& fd_;
  ExplorationFunction<Key>& fe_;
  unsigned blockSize_;
};

template <class Key, class Container>
HashTable<Key, Container>::HashTable(unsigned tableSize, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe, unsigned blockSize) {
  tableSize_ = tableSize;
  fe_ = fe;
  fd_ = fd;
  table_ = new Container*<Key>[tableSize_];
  blockSize_ = blockSize;
}

#endif  // HASHTABLE_H