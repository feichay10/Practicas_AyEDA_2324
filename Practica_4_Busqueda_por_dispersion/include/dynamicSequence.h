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

/**
 * @brief Class for implementing open addressing dispersion technique
 * 
 * @tparam Key 
 */
template <class Key>
class DynamicSequence : public Sequence<Key> {
 public:
  DynamicSequence();
  ~DynamicSequence();

  bool search(const Key& k) const override;
  bool insert(const Key& k) override;
  bool insertByFile(std::string file) override;
  bool remove(const Key& k) override;
  bool clear() override;
  bool isFull() const override;
  void print() override;

 private:
  Key* data_;
  unsigned size_ = 0;
};

/**
 * @brief Construct a new Dynamic Sequence< Key>:: Dynamic Sequence object
 * 
 * @tparam Key 
 */
template <class Key>
DynamicSequence<Key>::DynamicSequence() {
  data_ = new Key[size_];
}

/**
 * @brief Destroy the Dynamic Sequence< Key>:: Dynamic Sequence object
 * 
 * @tparam Key 
 */
template <class Key>
DynamicSequence<Key>::~DynamicSequence() {
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
bool DynamicSequence<Key>::search(const Key& k) const {
  for (int i = 0; i < size_; i++) {
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
 */
template <class Key>
bool DynamicSequence<Key>::insert(const Key& k) {
  size_++;
  Key* temp = new Key[size_];
  for (int i = 0; i < size_ - 1; ++i) {
    temp[i] = data_[i];
  }
  temp[size_ - 1] = k;
  delete[] data_;
  data_ = temp;
  return true;
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
bool DynamicSequence<Key>::insertByFile(std::string file) {
  std::ifstream fileStream(file);
  if (!fileStream.is_open()) {
    std::cout << "File " << file << " does not exist" << std::endl;
    return false;
  }
  Key key;
  while (fileStream >> key) {
    insert(key);
  }
  fileStream.close();
  return true;
}

/**
 * @brief Method that clears the table
 * 
 * @tparam Key 
 * @return true 
 */
template <class Key>
bool DynamicSequence<Key>::clear() {
  delete[] data_;
  size_ = 0;
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
bool DynamicSequence<Key>::remove(const Key& k) {
  size_--;
  Key* temp = new Key[size_];
  int j = 0;
  for (int i = 0; i < size_ + 1; ++i) {
    if (data_[i] != k) {
      temp[j] = data_[i];
      j++;
    }
  }
  delete[] data_;
  data_ = temp;
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
bool DynamicSequence<Key>::isFull() const {
  return false;
}

/**
 * @brief Method that prints the table
 * 
 * @tparam Key 
 */
template <class Key>
void DynamicSequence<Key>::print() {
  for (int i = 0; i < size_; ++i) {
    std::cout << "[" << data_[i] << "] ";
  }
}

#endif // DYNAMICSEQUENCE_H