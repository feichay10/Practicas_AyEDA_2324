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

#include "colors.h"
#include "dfModule.h"
#include "dfRandom.h"
#include "dfSum.h"
#include "dispersionFunction.h"
#include "dynamicSequence.h"
#include "efDoubleDispersion.h"
#include "efLineal.h"
#include "efQuadratic.h"
#include "efRedispersion.h"
#include "explorationFunction.h"
#include "sequence.h"
#include "staticSequence.h"

/**
 * @brief Class for implementing a hash table
 * 
 * @tparam Key 
 * @tparam Container 
 */
template <class Key, class Container = StaticSequence<Key>>
class HashTable {
 public:
  HashTable(unsigned tableSize, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe, unsigned blockSize) {
    tableSize_ = tableSize;
    fd_ = &fd;
    fe_ = &fe;
    blockSize_ = blockSize;
    createTable();
  }

  ~HashTable() {
    for (unsigned i = 0; i < tableSize_; i++) {
      delete table_[i];
    }
    delete[] table_;
  }

  // TODO: Fix this method, same as insert but searching for the element
  bool search(const Key& k) const {
    unsigned index = (*fd_)(k);
    unsigned i = 0;
    unsigned functionValue = (*fd_)(k);
    bool flag = true;
    while (flag) {
      if (i >= tableSize_) return false;
      if (table_[index]->search(k)) {
        return true;
      }
      if (!table_[index]->isFull()) {
        flag = false;
      }
      index = (functionValue + (*fe_)(k, i)) % tableSize_;
      i++;
    }
    return false;
  }

  bool insert(const Key& k) {
    unsigned index = (*fd_)(k); // Calculates the initial position using the dispersion function
    if (table_[index]->search(k)) {
      std::cout << RED_BOLD << "Element " << k << " already exists on the table" << RESET << std::endl;
      return false;
    }
    unsigned i = 1;
    unsigned functionValue = (*fd_)(k);
    while (table_[index]->isFull()) { // If the position is occupied, the new position is calculated.
      std::cout << "Collision in " << index << std::endl;
      unsigned explorationFunctionValue = (*fe_)(k, i);
      index = (functionValue + explorationFunctionValue) % tableSize_;
      i++;
      // Check if the table is full
      if (i == tableSize_) {
        std::cout << "Table is full" << std::endl;
        return false;
      }
    }
    std::cout << "Inserting " << k << " in " << index << std::endl;
    return table_[index]->insert(k);
  }

  bool insertByFile(std::string file) {
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

  bool remove(const Key& k) {
    unsigned index = (*fd_)(k);
    if (!table_[index]->search(k)) {
      std::cout << "Element " << k << " does not exist" << std::endl;
      return false;
    } else {
      std::cout << "Removing " << k << " from " << index << std::endl;
      return table_[index]->remove(k);
    }
    return false;
  }

  bool clear() {
    for (unsigned i = 0; i < tableSize_; i++) {
      table_[i]->clear();
    }
    return true;
  }

  void print() {
    for (int i = 0; i < tableSize_; ++i) {
      std::cout << i << ") [ ";
      table_[i]->print();
      std::cout << "]" << std::endl;
    }
  }

 private:
  void createTable() {
    table_ = new Sequence<Key>*[tableSize_];
    for (unsigned i = 0; i < tableSize_; i++) {
      table_[i] = new StaticSequence<Key>(blockSize_);
    }
  }

  unsigned tableSize_;
  Sequence<Key>** table_;
  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_;
  unsigned blockSize_;
};

/** 
 * @brief Class for implementing a hash table with dynamic sequence specialization
 * 
 * @tparam Key 
 */
template <class Key>
class HashTable <Key, DynamicSequence<Key>> {
 public:
  HashTable(unsigned tableSize, DispersionFunction<Key>& fd) {
    tableSize_ = tableSize;
    fd_ = &fd;
    createTable();
  }

  ~HashTable() {
    for (unsigned i = 0; i < tableSize_; i++) {
      delete table_[i];
    }
    delete[] table_;
  }

  bool search(const Key& k) const {
    unsigned index = (*fd_)(k);
    return table_[index]->search(k);
  }

  bool insert(const Key& k) {
    unsigned index = (*fd_)(k);
    if (table_[index]->search(k)) {
      std::cout << RED_BOLD << "Element " << k << " already exists on the table" << RESET << std::endl;
      return false;
    }
    std::cout << "Inserting " << k << " in " << index << std::endl;
    return table_[index]->insert(k);
  }
  bool insertByFile(std::string file) {
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

  bool remove(const Key& k) {
    unsigned index = (*fd_)(k);
    if (!table_[index]->search(k)) {
      std::cout << "Element " << k << " does not exist" << std::endl;
      return false;
    } else {
      std::cout << "Removing " << k << " from " << index << std::endl;
      return table_[index]->remove(k);
    }
    return false;
  
  }

  bool clear() {
    for (unsigned i = 0; i < tableSize_; i++) {
      table_[i]->clear();
    }
    return true;
  
  }

  void print() {
    for (int i = 0; i < tableSize_; ++i) {
      std::cout << i << ") [ ";
      table_[i]->print();
      std::cout << "]" << std::endl;
    }
  }

 private:
  void createTable() {
    table_ = new Sequence<Key>*[tableSize_];
    for (unsigned i = 0; i < tableSize_; i++) {
      table_[i] = new DynamicSequence<Key>();
    }
  }

  unsigned tableSize_;
  Sequence<Key>** table_;
  DispersionFunction<Key>* fd_;
};

#endif  // HASHTABLE_H