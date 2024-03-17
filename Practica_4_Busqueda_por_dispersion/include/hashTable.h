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
#include "../include/sequence.h"
#include "../include/staticSequence.h"

/**
 * @brief Class for implementing a hash table
 * 
 * @tparam Key 
 * @tparam Container 
 */
template <class Key, class Container = StaticSequence<Key>>
class HashTable {
 public:
  HashTable(unsigned tableSize, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe, unsigned blockSize); // Dispersion cerrada
  HashTable(unsigned tableSize, DispersionFunction<Key>& fd); // Dispersion abierta
  ~HashTable();

  bool search(const Key& k) const;
  bool insert(const Key& k);
  bool insertByFile(std::string file);
  bool remove(const Key& k);
  bool clear();
  void print();

 private:
  void createTable();

  unsigned tableSize_;
  Sequence<Key>** table_;
  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_;
  unsigned blockSize_;
};

/**
 * @brief Construct a new Hash Table< Key,  Container>:: Hash Table object
 * 
 * @tparam Key 
 * @tparam Container 
 * @param tableSize 
 * @param fd 
 * @param fe 
 * @param blockSize 
 */
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

/**
 * @brief Construct a new Hash Table< Key,  Container>:: Hash Table object
 * 
 * @tparam Key 
 * @tparam Container 
 * @param tableSize 
 * @param fd 
 */
template <class Key, class Container>
HashTable<Key, Container>::HashTable(unsigned tableSize,
                                     DispersionFunction<Key>& fd) {
  tableSize_ = tableSize;
  fd_ = &fd;
  createTable();
}

/**
 * @brief Destroy the Hash Table< Key,  Container>:: Hash Table object
 * 
 * @tparam Key 
 * @tparam Container 
 */
template <class Key, class Container>
HashTable<Key, Container>::~HashTable() {
  for (unsigned i = 0; i < tableSize_; i++) {
    delete table_[i];
  }
  delete[] table_;
}

/**
 * @brief Method that searches for a key in the table
 * 
 * @tparam Key 
 * @tparam Container 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key, class Container>
bool HashTable<Key, Container>::search(const Key& k) const {
  unsigned index = (*fd_)(k);
  return table_[index]->search(k);
}

/**
 * @brief Method that inserts a key in the table
 * 
 * @tparam Key 
 * @tparam Container 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key, class Container>
bool HashTable<Key, Container>::insert(const Key& k) {
  unsigned index = (*fd_)(k); // Calcula la posición inicial utilizando la función de dispersión
  if (typeid(Container) == typeid(StaticSequence<Key>)) {
    if (table_[index]->search(k)) {
      std::cout << "Element " << k << " already exists " << std::endl;
      return false;
    }
    unsigned i = 1;
    unsigned functionValue = (*fd_)(k);
    while (table_[index]->isFull()) { // Si la posición está ocupada, se calcula la nueva posición
      // if (table_[index]->isFull()) {
      //   std::cout << "Table is full" << std::endl;
      //   return false;
      // }
      std::cout << "Collision in " << index << std::endl;
      unsigned explorationFunctionValue = (*fe_)(k, i);
      index = (functionValue + explorationFunctionValue) % tableSize_;
      i++;

      // TODO: Check if the table is full when the exploration function is full
      if (table_[index]->isFull()) {
        std::cout << "Table is full" << std::endl;
        return false;
      }
    }
    std::cout << "Inserting " << k << " in " << index << std::endl;
    return table_[index]->insert(k);
  } else if (typeid(Container) == typeid(DynamicSequence<Key>)) {
    if (table_[index]->search(k)) {
      std::cout << "Element " << k << " already exists on the table" << std::endl;
      return false;
    }
    std::cout << "Inserting " << k << " in " << index << std::endl;
    return table_[index]->insert(k);
  }
  return false;
}

/**
 * @brief Method that inserts a key in the table from a file
 * 
 * @tparam Key 
 * @tparam Container 
 * @param file 
 * @return true 
 * @return false 
 */
template <class Key, class Container>
bool HashTable<Key, Container>::insertByFile(std::string file) {
  std::ifstream fileStream(file);
  if (!fileStream.is_open()) {
    std::cout << "File " << file << " not found." << std::endl;
    return false;
  }
  Key k;
  while (fileStream >> k) {
    if (k.checkNif(k) == false) {
      std::cout << "NIF " << k << " is not valid" << std::endl;
      continue;
    }
    if (typeid(Container) == typeid(StaticSequence<Key>)) {
      if (table_[(*fd_)(k)]->isFull()) {
        std::cout << "Table is full" << std::endl;
        return false;
      }
    } 
    insert(k);
  }
  fileStream.close();
  return true;
}

/**
 * @brief Method that removes a key from the table
 * 
 * @tparam Key 
 * @tparam Container 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key, class Container>
bool HashTable<Key, Container>::remove(const Key& k) {
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

/**
 * @brief Method that clears the table
 * 
 * @tparam Key 
 * @tparam Container 
 * @return true 
 * @return false 
 */
template <class Key, class Container>
bool HashTable<Key, Container>::clear() {
  for (unsigned i = 0; i < tableSize_; i++) {
    delete table_[i];
    table_[i]->clear();
  }
  return true;
}

/**
 * @brief Method that prints the table
 * 
 * @tparam Key 
 * @tparam Container 
 */
template <class Key, class Container>
void HashTable<Key, Container>::print() {
  for (int i = 0; i < tableSize_; ++i) {
    std::cout << i << ") [ ";
    table_[i]->print();
    std::cout << "]" << std::endl;
  }
}

/**
 * @brief Method that initializes the table
 * 
 * @tparam Key 
 * @tparam Container 
 */
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