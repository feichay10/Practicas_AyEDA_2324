/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 7: Implementacion del TDA AVL
 * @file AB.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AB_H
#define AB_H

#include <iostream>
#include <queue>

#include "nodeB.h"

template<class Key>
class AB {
 public:
  NodeB<Key>* getRoot() const;
  NodeB<Key>*& getRoot();
  void setRoot(NodeB<Key>* root);
  
  // Methods
  virtual bool insert(const Key& k) = 0;
  virtual bool search(const Key& k) const = 0;
  virtual bool remove(const Key& k) = 0;
  
  // Tour methods
  void inorder() const;
  void inorder(NodeB<Key>* node) const;
  void preorder() const;
  void preorder(NodeB<Key>* node) const;
  void postorder() const;
  void postorder(NodeB<Key>* node) const;
  void byLevel() const;
  void byLevel(NodeB<Key>* node) const;

  // Auxiliar methods
  int height() const;
  int heightN(NodeB<Key>* node) const;
  bool empty();

  virtual void write(std::ostream& os) const;
  friend std::ostream& operator<<(std::ostream& os, const AB<Key>& ab) {
    ab.write(os);
    return os;
  }

 protected:
  NodeB<Key>* root_;
};

template <class Key>
NodeB<Key>* AB<Key>::getRoot() const {
  return root_;
}

template <class Key>
NodeB<Key>*& AB<Key>::getRoot() {
  return root_;
}

template <class Key>
void AB<Key>::setRoot(NodeB<Key>* root) {
  root_ = root;
}

template <class Key>
void AB<Key>::inorder() const {
  inorder(root_);
}

template<class Key>
void AB<Key>::inorder(NodeB<Key>* node) const {
  if (node != nullptr) {
    inorder(node->getLeft());
    std::cout << BLUE_BOLD << node->getData() << " " << RESET;
    inorder(node->getRight());
  } 
}

template <class Key>
void AB<Key>::preorder() const {
  preorder(root_);
}

template<class Key>
void AB<Key>::preorder(NodeB<Key>* node) const {
  if (node != nullptr) {
    std::cout << BLUE_BOLD << node->getData() << " " << RESET;
    preorder(node->getLeft());
    preorder(node->getRight());
  }
}

template <class Key>
void AB<Key>::postorder() const {
  postorder(root_);
}

template<class Key>
void AB<Key>::postorder(NodeB<Key>* node) const {
  if (node != nullptr) {
    postorder(node->getLeft());
    postorder(node->getRight());
    std::cout << BLUE_BOLD << node->getData() << " " << RESET;
  }
}

template <class Key>
void AB<Key>::byLevel() const {
  byLevel(root_);
}

template<class Key>
void AB<Key>::byLevel(NodeB<Key>* node) const {
  std::queue<NodeB<Key>*> queue;
  queue.push(node);
  while (!queue.empty()) {
    if (queue.front() != nullptr) {
      std::cout << BLUE_BOLD << queue.front()->getData() << " " << RESET;
      queue.push(queue.front()->getLeft());
      queue.push(queue.front()->getRight());
    }
    queue.pop();
  }
}

template <class Key>
int AB<Key>::height() const {
  return heightN(root_);
}

template <class Key>
int AB<Key>::heightN(NodeB<Key>* node) const {
  if (node == nullptr) {
    return 0;
  } else {
    int leftHeight = heightN(node->getLeft());
    int rightHeight = heightN(node->getRight());

    if (leftHeight > rightHeight) {
      return leftHeight + 1;
    } else {
      return rightHeight + 1;
    }
  }
}

template<class Key>
bool AB<Key>::empty() {
  return root_ == nullptr;
}

template <class Key>
void AB<Key>::write(std::ostream& os) const {
  int k = 0;
  std::queue<NodeB<Key>*> queue, queueAux;
  queue.push(root_);
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
    os << std::endl;
    k++;
  }
}

#endif // AB_H