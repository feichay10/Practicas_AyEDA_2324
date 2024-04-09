/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementacion del TDA Árbol
 * @file AB.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-22
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
  NodeB<Key>* getRoot();
  
  virtual bool insert(const Key& k) = 0;
  virtual bool search(const Key& k) const = 0;
  void inorder() const;
  void inorder(NodeB<Key>* node) const;
  // virtual bool empty() = 0;

  void write(std::ostream& os) const;
  friend std::ostream& operator<<(std::ostream& os, const AB<Key>& ab) {
    ab.write(os);
    return os;
  }

 protected:
  NodeB<Key>* root_;
};

template<class Key>
NodeB<Key>* AB<Key>::getRoot() {
  return root_;
}

template <typename Key>
void AB<Key>::inorder() const {
  inorder(root_);
}

template<class Key>
void AB<Key>::inorder(NodeB<Key>* node) const {
  if (node != nullptr) {
    inorder(node->getLeft());
    std::cout << "\033[36m\033[1m" << node->getData() << " " << "\033[0m";
    inorder(node->getRight());
  }
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
    k++;
    os << "\n";
  }
}

#endif // AB_H