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

/**
 * @brief Class ABE (balanced binary tree) that inherits from AB.
 * 
 * @tparam Key 
 */
template<class Key>
class ABE : public AB<Key> {
 public:
  bool insert(const Key& k) override;
  bool search(const Key& k) const override;
  bool remove(const Key& k) override;

 private:
  bool insertBalBranch(NodeB<Key>*& node, const Key k);
  const int branchSize(NodeB<Key>* node) const;
  bool searchBalBranch(NodeB<Key>* node, const Key k) const;
};

/**
 * @brief Inserts a new node in the balanced binary tree.
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template<class Key>
bool ABE<Key>::insert(const Key& k) {
  if (search(k)) {
    return false;
  }

  this->numNodes_++;
  if (AB<Key>::root_ == nullptr) {
    AB<Key>::root_ = new NodeB<Key>(k);
    return true;
  } else {
    return insertBalBranch(AB<Key>::root_, k);
  }
}

/**
 * @brief Inserts a new node in the balanced binary tree.
 * 
 * @tparam Key 
 * @param node 
 * @param k 
 * @return true 
 * @return false 
 */
template<class Key>
bool ABE<Key>::insertBalBranch(NodeB<Key>*& node, const Key k) {
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
  return true;
}

/**
 * @brief Get the size of the branch
 * 
 * @tparam Key 
 * @param node 
 * @return int 
 */
template<class Key>
const int ABE<Key>::branchSize(NodeB<Key>* node) const {
  if (node == NULL) {
    return 0;
  }
  return (1 + branchSize(node->getLeft()) + branchSize(node->getRight()));
}

/**
 * @brief Searches for a node in the balanced binary tree.
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template<class Key>
bool ABE<Key>::search(const Key& k) const {
  return searchBalBranch(AB<Key>::root_, k);
}

/**
 * @brief Searches for a node in the balanced binary tree.
 * 
 * @tparam Key 
 * @param node 
 * @param k 
 * @return true 
 * @return false 
 */
template<class Key>
bool ABE<Key>::searchBalBranch(NodeB<Key>* node, const Key k) const {
  if (node == nullptr) {
    return false;
  }
  if (node->getData() == k) {
    return true;
  }
  if (searchBalBranch(node->getLeft(), k)) {
    return true;
  }
  return searchBalBranch(node->getRight(), k);
}

/**
 * @brief Removes a node from the balanced binary tree.
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template<class Key>
bool ABE<Key>::remove(const Key& k) {
  return false;
}

#endif // ABE_H