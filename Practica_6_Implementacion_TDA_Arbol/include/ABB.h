/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementacion del TDA Árbol
 * @file ABB.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ABB_H
#define ABB_H

#include "AB.h"

template <class Key>
class ABB : public AB<Key> {
 public:
  bool insert(const Key& k);
  bool search(const Key& k) const;

 private:
  bool insertBranch(NodeB<Key>*& node, Key k);
  bool searchBranch(NodeB<Key>* node, Key k) const;
};

template <class Key>
bool ABB<Key>::insert(const Key& k) {
  if (this->getRoot() == nullptr) {
    AB<Key>::root_ = new NodeB<Key>(k);
    return true;
  } else {
    return insertBranch(AB<Key>::root_, k);
  }
}

template <class Key>
bool ABB<Key>::insertBranch(NodeB<Key>*& node, Key k) {
  if (search(k)) {
    return false;
  }
  if (node == nullptr) {
    node = new NodeB<Key>(k);
  } else if (k < node->getData()) {
    insertBranch(node->getLeft(), k);
  } else {
    insertBranch(node->getRight(), k);
  }
  return true;
}

template <class Key>
bool ABB<Key>::search(const Key& k) const {
  return searchBranch(AB<Key>::root_, k);
}

template <class Key>
bool ABB<Key>::searchBranch(NodeB<Key>* node, Key k) const {
  if (node == nullptr) {
    return false;
  }
  if (k == node->getData()) {
    return true;
  }
  if (k < node->getData()) {
    return searchBranch(node->getLeft(), k);
  }
  return searchBranch(node->getRight(), k);
}

#endif // ABB_H