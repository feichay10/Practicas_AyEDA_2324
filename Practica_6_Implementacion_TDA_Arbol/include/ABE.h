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

 private:
  bool insertBalBranch(const Key k, NodeB<Key>*& node);
  int branchSize(NodeB<Key>* node) const;
};

template<class Key>
bool ABE<Key>::insert(const Key& k) {
  if (AB<Key>::root_ == nullptr) {
    AB<Key>::root_ = new NodeB<Key>(k);
    return true;
  } else {
    // if (search(k)) {
    //   return false;
    // }
    return insertBalBranch(k, AB<Key>::root_);
  }
}

template<class Key>
bool ABE<Key>::insertBalBranch(const Key k, NodeB<Key>*& node) {
  if (branchSize(node->getLeft()) <= branchSize(node->getRight())) {
    if (node->getLeft() != nullptr) {
      insertBalBranch(k, node->getLeft());
    } else {
      node->setLeft(new NodeB<Key>(k));
    }
  } else {
    if (node->getRight() != nullptr) {
      insertBalBranch(k, node->getRight());
    } else {
      node->setRight(new NodeB<Key>(k));
    }
  }
  return true;
}

template<class Key>
int ABE<Key>::branchSize(NodeB<Key>* node) const {
  if (node == NULL) {
    return 0;
  }
  return (1 + branchSize(node->getLeft()) + branchSize(node->getRight()));
}

template<class Key>
bool ABE<Key>::search(const Key& k) const {
  return true;
}

#endif // ABE_H