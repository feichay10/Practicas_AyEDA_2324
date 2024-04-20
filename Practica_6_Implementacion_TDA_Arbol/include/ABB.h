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

/**
 * @brief Class ABB (binary search tree) that inherits from AB.
 * 
 * @tparam Key 
 */
template <class Key>
class ABB : public AB<Key> {
 public:
  bool insert(const Key& k) override;
  bool search(const Key& k) const override;
  bool remove(const Key& k) override;

 private:
  bool insertBranch(NodeB<Key>*& node, Key k);
  bool searchBranch(NodeB<Key>* node, Key k) const;
  bool removeBranch(NodeB<Key>*& node, Key k);
  bool replace(NodeB<Key>*& deleteNode, NodeB<Key>*& substituteNode);
};

/**
 * @brief Inserts a new node in the binary search tree.
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABB<Key>::insert(const Key& k) {
  if (search(k)) {
    return false;
  }

  this->nodes_++;
  return insertBranch(AB<Key>::root_, k);
}

/**
 * @brief Inserts a new node in the binary search tree.
 * 
 * @tparam Key 
 * @param node 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABB<Key>::insertBranch(NodeB<Key>*& node, Key k) {
  if (node == nullptr) {
    node = new NodeB<Key>(k);
  } else if (k < node->getData()) {
    insertBranch(node->getLeft(), k);
  } else {
    insertBranch(node->getRight(), k);
  }
  
  return true;
}

/**
 * @brief Searches for a node in the binary search tree.
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABB<Key>::search(const Key& k) const {
  return searchBranch(AB<Key>::root_, k);
}

/**
 * @brief Searches for a node in the binary search tree.
 * 
 * @tparam Key 
 * @param node 
 * @param k 
 * @return true 
 * @return false 
 */
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

/**
 * @brief Removes a node from the binary search tree.
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABB<Key>::remove(const Key& k) {
  if (!search(k)) {
    return false;
  }

  this->nodes_--;
  return removeBranch(AB<Key>::root_, k);
}

/**
 * @brief Removes a node from the binary search tree.
 * 
 * @tparam Key 
 * @param node 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABB<Key>::removeBranch(NodeB<Key>*& node, Key k) {
  if (node == nullptr) {
    return false;
  }
  if (k < node->getData()) {
    return removeBranch(node->getLeft(), k);
  } else if (k > node->getData()) {
    return removeBranch(node->getRight(), k);
  } else {  // k == node->getData()
    NodeB<Key>* deleteNode = node;
    if (node->getRight() == nullptr) {
      node = node->getLeft();
    } else if (node->getLeft() == nullptr) {
      node = node->getRight();
    } else {
      replace(deleteNode, node->getLeft());
    }
    delete deleteNode;
  }

  return true;
}

/**
 * @brief Replaces a node with another node.
 * 
 * @tparam Key 
 * @param deleteNode 
 * @param substituteNode 
 * @return true 
 */
template <class Key>
bool ABB<Key>::replace(NodeB<Key>*& deleteNode, NodeB<Key>*& substituteNode) {
  if (substituteNode->getRight() != nullptr) {
    replace(deleteNode, substituteNode->getRight());
  } else {
    deleteNode->setData(substituteNode->getData());
    deleteNode = substituteNode;
    substituteNode = substituteNode->getLeft();
  }
  return true;
}

#endif // ABB_H