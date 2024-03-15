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
  bool insertByFile(std::string file);
  bool remove(const Key& k);
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

template <class Key, class Container>
bool HashTable<Key, Container>::search(const Key& k) const {
  unsigned index = (*fd_)(k);
  if (typeid(Container) == typeid(StaticSequence<Key>)) {
    return table_[index]->search(k);
  } else if (typeid(Container) == typeid(DynamicSequence<Key>)) {
    return table_[index]->search(k);
  }
  return false;
}

// h(x) = x mod tableSize_ 		
// g(x,i) = i*i (fd_)
// (h(x) + g(x,i)) mod 7 
template <class Key, class Container>
bool HashTable<Key, Container>::insert(const Key& k) {
  unsigned index = (*fd_)(k); // Calcula la posición inicial utilizando la función de dispersión
  if (typeid(Container) == typeid(StaticSequence<Key>)) {
    unsigned i = 1;
    while (table_[index]->isFull()) {
      std::cout << "Index: " << index << std::endl;
      std::cout << "Element " << k << " cannot be inserted in " << index << " because it is full." << std::endl;
      index = (index + (*fe_)(k, i)) % tableSize_;
      std::cout << "New index: " << index << std::endl;
      i++;
    }
    std::cout << "Inserting " << k << " in " << index << std::endl;
    return table_[index]->insert(k);


  } else if (typeid(Container) == typeid(DynamicSequence<Key>)) {
    std::cout << "Inserting " << k << " in " << index << std::endl;
    return table_[index]->insert(k);
  }
  return false;
}

template <class Key, class Container>
bool HashTable<Key, Container>::insertByFile(std::string file) {
  std::ifstream fileStream(file);
  if (!fileStream.is_open()) {
    std::cout << "File " << file << " not found." << std::endl;
    return false;
  }
  Key k;
  while (fileStream >> k) {
    insert(k);
  }
  fileStream.close();
  return true;
}

template <class Key, class Container>
bool HashTable<Key, Container>::remove(const Key& k) {
  unsigned index = (*fd_)(k);
  if (typeid(Container) == typeid(StaticSequence<Key>)) {
    return table_[index]->remove(k);
  } else if (typeid(Container) == typeid(DynamicSequence<Key>)) {
    return table_[index]->remove(k);
  }
  return false;
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
      table_[i] = new StaticSequence<Key>(blockSize_);
    }
  } else if (typeid(Container) == typeid(DynamicSequence<Key>)) {
    for (unsigned i = 0; i < tableSize_; i++) {
      table_[i] = new DynamicSequence<Key>();
    }
  }
}

#endif  // HASHTABLE_H