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
  HashTable(unsigned tableSize, DispersionFunction<Key>& fd,
            ExplorationFunction<Key>& fe,
            unsigned blockSize);           // Dispersion cerrada
  HashTable(unsigned tableSize,
            DispersionFunction<Key>& fd);  // Dispersion abierta
  ~HashTable();

  bool search(const Key& k) const;
  bool insert(const Key& k);
  void print();

 private:
  void createTable();

  unsigned tableSize_;
  Sequence<Key>** table_;
  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_;
  unsigned blockSize_;
};

template <class Key, class Container>
HashTable<Key, Container>::HashTable(unsigned tableSize,
                                     DispersionFunction<Key>& fd,
                                     ExplorationFunction<Key>& fe,
                                     unsigned blockSize) {
  tableSize_ = tableSize;
  fd_ = &fd;
  fe_ = &fe;
  blockSize_ = blockSize;
  createTable();
}

template <class Key, class Container>
HashTable<Key, Container>::HashTable(unsigned tableSize,
                                     DispersionFunction<Key>& fd) {
  tableSize_ = tableSize;
  fd_ = &fd;
  createTable();
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

template <class Key, class Container>
bool HashTable<Key, Container>::insert(const Key& k) {
  bool output = false;
  unsigned index = (*fd_)(k);
  if (table_[index]->insert(k)) {
    output = true;
  } else {
    int attempt = 0;
    while (attempt < blockSize_ && !table_[index]->insert(k)) {
      index = (*fe_)(k, index);
      if (table_[index]->insert(k)) output = true;
      attempt++;
    }
  }
  return output;
}

template <class Key, class Container>
void HashTable<Key, Container>::print() {
  for (int i = 0; i < tableSize_; ++i) {
    std::cout << i << ") [ ";
    table_[i]->print();
    std::cout << "]" << std::endl;
  }
}

template <class Key, class Container>
void HashTable<Key, Container>::createTable() {
  table_ = new Sequence<Key>*[tableSize_];
  if (typeid(Container) == typeid(StaticSequence<Key>)) {
    for (unsigned i = 0; i < tableSize_; i++) {
      // table_[i] = new StaticSequence<Key>(blockSize_);

    }
  } else if (typeid(Container) == typeid(DynamicSequence<Key>)) {
    for (unsigned i = 0; i < tableSize_; i++) {
      table_[i] = new DynamicSequence<Key>();
    }
  }
}

#endif  // HASHTABLE_H