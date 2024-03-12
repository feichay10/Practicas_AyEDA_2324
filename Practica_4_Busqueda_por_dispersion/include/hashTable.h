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

#include "../include/dfModule.h"
#include "../include/dfRandom.h"
#include "../include/dfSum.h"
#include "../include/dispersionFunction.h"
#include "../include/dynamicSequence.h"
#include "../include/efDoubleDispersion.h"
#include "../include/efLineal.h"
#include "../include/efQuadratic.h"
#include "../include/efRedispersion.h"
#include "../include/explorationFunction.h"
#include "../include/functions.h"
#include "../include/sequence.h"
#include "../include/staticSequence.h"

template <class Key, class Container = StaticSequence<Key>>
class HashTable {
 public:
  HashTable(unsigned tableSize, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe, unsigned blockSize);  // Dispersion cerrada
  HashTable(unsigned tableSize, DispersionFunction<Key>& fd);  // Dispersion abierta
  ~HashTable();

  bool search(const Key& k) const;
  bool insert(const Key& k);

  std::ostream& operator<<(std::ostream& os) const;

 private:
  unsigned tableSize_;
  Container** table_;
  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_;
  unsigned blockSize_;
};

// template <class Key, class Container>
// HashTable<Key, Container>::HashTable(unsigned tableSize,
//                                      DispersionFunction<Key>& fd,
//                                      ExplorationFunction<Key>& fe,
//                                      unsigned blockSize)
//     : tableSize_(tableSize), fd_(fd), fe_(fe), blockSize_(blockSize) {
//   table_ = new Container*[tableSize_];
//   for (unsigned i = 0; i < tableSize_; i++) {
//     table_[i] = new Container(blockSize_);
//   }
// }

template <class Key, class Container>
HashTable<Key, Container>::HashTable(unsigned tableSize, DispersionFunction<Key>& fd) {
  tableSize_ = tableSize;
  fd_ = &fd;
  table_ = new Container*[tableSize_];
  for (unsigned i = 0; i < tableSize_; i++) {
    table_[i] = new Container();
  }
}

template <class Key, class Container>
HashTable<Key, Container>::~HashTable() {
  for (unsigned i = 0; i < tableSize_; i++) {
    delete table_[i];
  }
  delete[] table_;
}

// template <class Key, class Container>
// bool HashTable<Key, Container>::search(const Key& k) const {
//   unsigned index = fd_(k, tableSize_);
//   unsigned i = 0;
//   while (i < tableSize_ && !table_[index]->empty()) {
//     if (table_[index]->search(k)) {
//       return true;
//     }
//     index = (index + fe_(k, i, tableSize_)) % tableSize_;
//     i++;
//   }
//   return false;
// }

// template <class Key, class Container>
// bool HashTable<Key, Container>::insert(const Key& k) {
//   unsigned index = fd_(k, tableSize_);
//   unsigned i = 0;
//   while (i < tableSize_ && !table_[index]->empty()) {
//     index = (index + fe_(k, i, tableSize_)) % tableSize_;
//     i++;
//   }
//   if (i < tableSize_) {
//     table_[index]->insert(k);
//     return true;
//   }
//   return false;
// }

// Prunsigned the hash table as:
// 0 | 1 | 2 | 3 | 4 | 5 | ... | tableSize-1  -> Position
// 1 | 2 | 3 | 4 | 5 | 6 | ... | tableSize    -> Values
template <class Key, class Container>
std::ostream& HashTable<Key, Container>::operator<<(std::ostream& os) const {
  for (unsigned i = 0; i < tableSize_; i++) {
    os << i << " | ";
  }
  os << std::endl;
  for (unsigned i = 0; i < tableSize_; i++) {
    os << table_[i] << " | ";
  }
  os << std::endl;
  return os;
}

#endif  // HASHTABLE_H