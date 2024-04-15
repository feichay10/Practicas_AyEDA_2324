/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file staticSequence.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef STATICSEQUENCE_H
#define STATICSEQUENCE_H

#include "sequence.h"
#include <vector>

/**
 * @brief Class for implementing close addressing dispersion technique
 * 
 * @tparam Key 
 */
template <class Key>
class StaticSequence : public Sequence<Key> {
 public:
  StaticSequence(unsigned blockSize);
  ~StaticSequence();

  bool search(const Key& k) const override;
  bool insert(const Key& k) override;
  bool insertByFile(std::string file) override;
  bool remove(const Key& k) override;
  bool clear() override;
  bool isFull() const override;
  void print() override;

 private:
  Key* data_;
  unsigned blockSize_;
};

/**
 * @brief Construct a new Static Sequence< Key>:: Static Sequence object
 * 
 * @tparam Key 
 * @param blockSize 
 */
template <class Key>
StaticSequence<Key>::StaticSequence(unsigned blockSize) {
  data_ = new Key[blockSize];
  // Clear the contents of the array
  for (unsigned i = 0; i < blockSize; i++) {
    data_[i] = 0;
  }
  blockSize_ = blockSize;
}

/**
 * @brief Destroy the Static Sequence< Key>:: Static Sequence object
 * 
 * @tparam Key 
 */
template <class Key>
StaticSequence<Key>::~StaticSequence() {
  delete[] data_;
}

/**
 * @brief Method that searches for a key in the table
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool StaticSequence<Key>::search(const Key& k) const {
  for (unsigned i = 0; i < blockSize_; i++) {
    if (data_[i] == k) {
      return true;
    }
  }
  return false;
}


/**
 * @brief Method that inserts a key in the table
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool StaticSequence<Key>::insert(const Key& k) {
  for (unsigned i = 0; i < blockSize_; i++) {
    if (data_[i] == 0) {
      data_[i] = k;
      return true;
    }
  }
  return false;
}

/**
 * @brief Method that inserts a key in the table from a file
 * 
 * @tparam Key 
 * @param file 
 * @return true 
 * @return false 
 */
template <class Key>
bool StaticSequence<Key>::insertByFile(std::string file) {
  std::ifstream fileStream(file);
  Key* keys = new Key[blockSize_];
  Key key;
  unsigned count = 0;
  while (fileStream >> key && count < blockSize_) {
    keys[count] = key;
    count++;
  }
  fileStream.close();
  for (unsigned i = 0; i < count; i++) {
    insert(keys[i]);
  }
  delete[] keys;
  return true;
}

/**
 * @brief Method that checks if the index is full
 * 
 * @tparam Key 
 * @return true 
 * @return false 
 */
template <class Key>
bool StaticSequence<Key>::isFull() const {
  for (unsigned i = 0; i < blockSize_; i++) {
    if (data_[i] == 0) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Method that removes a key from the table
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool StaticSequence<Key>::remove(const Key& k) {
  for (unsigned i = 0; i < blockSize_; i++) {
    if (data_[i] == k) {
      data_[i] = 0;
      std::cout << "Element " << k << " removed " << std::endl;
      // Shift the elements to the left and remove the last element
      for (unsigned j = i; j < blockSize_ - 1; j++) {
        data_[j] = data_[j + 1];
      }
      data_[blockSize_ - 1] = 0;
      return true;
    }
  }
  return false;
}

/**
 * @brief Method that clears the table
 * 
 * @tparam Key 
 * @return true 
 * @return false 
 */
template <class Key>
bool StaticSequence<Key>::clear() {
  for (unsigned i = 0; i < blockSize_; i++) {
    data_[i] = 0;
  }
  return true;
}

/**
 * @brief Method that prints the table
 * 
 * @tparam Key 
 */
template <class Key>
void StaticSequence<Key>::print() {
  for (unsigned i = 0; i < blockSize_; ++i) {
    std::cout << "[" << data_[i] << "] ";
  }  
}

#endif  // STATICSEQUENCE_H