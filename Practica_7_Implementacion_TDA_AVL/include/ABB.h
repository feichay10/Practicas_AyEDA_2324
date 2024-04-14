/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 7: Implementacion del TDA AVL
 * @file ABB.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-29
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
  bool insert(const Key& k) override;
  bool search(const Key& k) const override;
  bool remove(const Key& k) override;

  void write(std::ostream& os) const override ;

 private:
  bool insertBranch(NodeB<Key>*& node, Key k);
  bool searchBranch(NodeB<Key>* node, Key k) const;
  bool removeBranch(NodeB<Key>*& node, Key k);

  bool replace(NodeB<Key>*& deleteNode, NodeB<Key>*& substituteNode);
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

template <class Key>
bool ABB<Key>::remove(const Key& k) {
  return removeBranch(AB<Key>::root_, k);
}

template <class Key>
bool ABB<Key>::removeBranch(NodeB<Key>*& node, Key k) {
  if (node == nullptr) {
    return false;
  }
  if (k < node->getData()) {
    return removeBranch(node->getLeft(), k);
  } else if (k > node->getData()) {
    return removeBranch(node->getRight(), k);
  } else { // k == node->getData()
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

template <class Key>
void ABB<Key>::write(std::ostream& os) const {
  int k = 0;
  std::queue<NodeB<Key>*> queue, queueAux;
  queue.push(AB<Key>::root_);
  while (!queue.empty()) {
    os << "Level " << k << ": ";
    while (!queue.empty()) {
      if (queue.front() != nullptr) {
        os << "[" << queue.front()->getData() << "]";
        queueAux.push(queue.front()->getLeft());
        queueAux.push(queue.front()->getRight());
      } else {
        os << "[.]";
      }
      queue.pop();
    }
    queue = queueAux;
    while (!queueAux.empty()) {
      queueAux.pop();
    }
    k++;
    os << "\n";
  }
}

#endif // ABB_H