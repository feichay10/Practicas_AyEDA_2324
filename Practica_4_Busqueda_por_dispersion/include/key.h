/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 * @file key.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef KEY_H
#define KEY_H

#include <iostream>

template <typename T>
class Key {
 public:
  Key() = default;
  Key(T key) : key_(key) {}
  ~Key() = default;

  T getKey() const { return key_; }
  void setKey(T key) { key_ = key; }

  // Overload operators
  bool operator<(const Key<T> &other) const;
  bool operator>(const Key<T> &other) const;
  bool operator<=(const Key<T> &other) const;
  bool operator>=(const Key<T> &other) const;
  bool operator==(const Key<T> &other) const;
  T operator/(const Key<T> &other) const;
  friend std::istream& operator>>(std::istream& is, Key& key) {
    is >> key.key_;
    return is;
  }

  friend std::ostream& operator<<(std::ostream& os, const Key& key) {
    os << key.key_;
    return os;
  }

 private:
  T key_;
};

template <typename T>
bool Key<T>::operator<(const Key<T> &other) const {
  return key_ < other.key_;
}

template <typename T>
bool Key<T>::operator>(const Key<T> &other) const {
  return key_ > other.key_;
}

template <typename T>
bool Key<T>::operator<=(const Key<T> &other) const {
  return key_ <= other.key_;
}

template <typename T>
bool Key<T>::operator>=(const Key<T> &other) const {
  return key_ >= other.key_;
}

template <typename T>
bool Key<T>::operator==(const Key<T> &other) const {
  return key_ == other.key_;
}

template <typename T>
T Key<T>::operator/(const Key<T> &other) const {
  return key_ / other.key_;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Key<T> &key) {
  os << key.key_;
  return os;
}

template <typename T>
std::istream &operator>>(std::istream &is, const Key<T> &key) {
  is >> key.key_;
  return is;
}

#endif  // KEY_H