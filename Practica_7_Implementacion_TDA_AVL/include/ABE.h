/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 7: Implementacion del TDA AVL
 * @file ABE.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-29
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
  bool remove(const Key& k) override;

  void write(std::ostream& os) const override;

 private:
  bool insertBalBranch(NodeB<Key>*& node, const Key k);
  bool searchBalBranch(NodeB<Key>* node, const Key k) const;
  bool removeBranch(NodeB<Key>*& node, const Key k);

  int branchSize(NodeB<Key>* node) const;
  bool replace(NodeB<Key>*& deleteNode, NodeB<Key>*& substituteNode);
};

template<class Key>
bool ABE<Key>::insert(const Key& k) {
  if (AB<Key>::root_ == nullptr) {
    AB<Key>::root_ = new NodeB<Key>(k);
    return true;
  } else {
    if (search(k)) {
      return false;
    }
    return insertBalBranch(AB<Key>::root_, k);
  }
}

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

template<class Key>
int ABE<Key>::branchSize(NodeB<Key>* node) const {
  if (node == NULL) {
    return 0;
  }
  return (1 + branchSize(node->getLeft()) + branchSize(node->getRight()));
}

template<class Key>
bool ABE<Key>::search(const Key& k) const {
  return searchBalBranch(AB<Key>::root_, k);
}

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

template<class Key>
bool ABE<Key>::remove(const Key& k) {
  if (!search(k)) {
    return false;
  }

  return removeBranch(AB<Key>::root_, k);
}

template <class Key>
bool ABE<Key>::removeBranch(NodeB<Key>*& node, Key k) {
  if (node == nullptr) {
    return false;
  } 

  if (search(k) == false) {
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
bool ABE<Key>::replace(NodeB<Key>*& deleteNode, NodeB<Key>*& substituteNode) {
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
void ABE<Key>::write(std::ostream& os) const {
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

#endif // ABE_H