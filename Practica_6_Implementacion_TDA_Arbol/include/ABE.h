/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementacion del TDA Árbol
 * @file ABE.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ABE_H
#define ABE_H

#include "AB.h"

template<class Key>
class ABE : public AB<Key> {
 public:
  bool insert(const Key& k) override;
  bool search(const Key& k) const override;
  const int size();

 private:
  bool insertBalBranch(NodeB<Key>*& node, Key k);
  const int branchSize(NodeB<Key>* node);
};

template<class Key>
bool ABE<Key>::insert(const Key& k) {
  if (AB<Key>::root_ == nullptr) {
    AB<Key>::root_ = new NodeB<Key>(k);
    return true;
  } else {
    return insertBalBranch(AB<Key>::root_, k);
  }
}

template<class Key>
bool ABE<Key>::insertBalBranch(NodeB<Key>*& node, Key k) {
  if (search(k)) {
    return false;
  }

  if (branchSize(node->getLeft()) <= branchSize(node->getRight())) {
    if (node->getLeft() != nullptr) {
      insertBalBranch(node->getLeft(), k);
    } else {
      node->setLeft(new NodeB<Key>(k));
    }
  } else {
    if (node->getRight() != nullptr) {
      insertBalBranch(node->getRight(), k);
    } else {
      node->setRight(new NodeB<Key>(k));
    }
  }
}

template<class Key>
bool ABE<Key>::search(const Key& k) const {
  return true;
}

template<class Key>
const int ABE<Key>::size() {
  return branchSize(AB<Key>::root_);
}

template<class Key>
const int ABE<Key>::branchSize(NodeB<Key>* node) {
  if (node == nullptr) {
    return 0;
  }
  return (1 + branchSize(node->getLeft()) + branchSize(node->getRight()));
}

#endif // ABE_H