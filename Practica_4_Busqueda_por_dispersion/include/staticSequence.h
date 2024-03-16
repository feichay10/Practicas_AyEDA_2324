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

  bool search(const Key& k) const;
  bool insert(const Key& k);
  bool insertByFile(std::string file);
  bool remove(const Key& k);
  bool clear();
  bool isFull() const;
  void print();

 private:
  Key* data_;
  unsigned blockSize_;
};

template <class Key>
StaticSequence<Key>::StaticSequence(unsigned blockSize) {
  data_ = new Key[blockSize];
  // Clear the contents of the array
  for (unsigned i = 0; i < blockSize; i++) {
    data_[i] = 0;
  }
  blockSize_ = blockSize;
}

template <class Key>
StaticSequence<Key>::~StaticSequence() {
  delete[] data_;
}

template <class Key>
bool StaticSequence<Key>::search(const Key& k) const {
  for (unsigned i = 0; i < blockSize_; i++) {
    if (data_[i] == k) {
      return true;
    }
  }
  return false;
}

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

template <class Key>
bool StaticSequence<Key>::insertByFile(std::string file) {
  std::ifstream fileStream(file);
  std::vector<Key> keys;
  Key key;
  while (fileStream >> key) {
    keys.push_back(key);
  }
  fileStream.close();
  for (unsigned i = 0; i < keys.size(); i++) {
    insert(keys[i]);
  }
  return true;
}

template <class Key>
bool StaticSequence<Key>::isFull() const {
  for (unsigned i = 0; i < blockSize_; i++) {
    if (data_[i] == 0) {
      return false;
    }
  }
  return true;
}

// TODO: Remove the element from the array and shift the elements to the left
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

template <class Key>
bool StaticSequence<Key>::clear() {
  for (unsigned i = 0; i < blockSize_; i++) {
    data_[i] = 0;
  }
  return true;
}

template <class Key>
void StaticSequence<Key>::print() {
  for (unsigned i = 0; i < blockSize_; ++i) {
    if (data_[i] == 0) {
      std::cout << "[" << data_[i] << "] ";
    } else {
      std::cout << "[" << data_[i] << data_[i].letterNif(data_[i]) << "] ";
    }
  }  
}

#endif  // STATICSEQUENCE_H