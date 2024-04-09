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

#include <stack>

#include "AB.h"

template<class Key>
class ABB : public AB<Key> {
 public:
  ABB() = default;
  ~ABB() = default;

  bool insert(const Key& k) override;
  bool search(const Key& k) const override;
  void inorder() const override;
  bool empty() override;
};

template<class Key>
bool ABB<Key>::insert(const Key& k) {
  NodeB<Key>* current = AB<Key>::getRoot();
  NodeB<Key>* parent = nullptr;
  NodeB<Key>* newNode = new NodeB<Key>(k, nullptr, nullptr);

  while (current != nullptr) {
    parent = current;
    if (k < current->getData()) {
      current = current->getLeft();
    } else if (k > current->getData()) {
      current = current->getRight();
    } else {
      delete newNode;
      return false;
    }
  }

  if (parent == nullptr) {
    AB<Key>::setRoot(newNode);
  } else if (k < parent->getData()) {
    parent->setLeft(newNode);
  } else {
    parent->setRight(newNode);
  }

  return true;
}

template<class Key>
bool ABB<Key>::search(const Key& k) const {
  NodeB<Key>* current = AB<Key>::getRoot();
  while (current != nullptr) {
    if (k == current->getData()) {
      return true;
    } else if (k < current->getData()) {
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }

  return false;
}

template<class Key>
void ABB<Key>::inorder() const {
  std::stack<NodeB<Key>*> stack;
  NodeB<Key>* current = AB<Key>::getRoot();
  while (current != nullptr || !stack.empty()) {
    while (current != nullptr) {
      stack.push(current);
      current = current->getLeft();
    }
    current = stack.top();
    stack.pop();
    std::cout << current->getData() << " ";
    current = current->getRight();
  }
  std::cout << std::endl;
}

template<class Key>
bool ABB<Key>::empty() {
  return AB<Key>::getRoot() == nullptr;
}

#endif // ABB_H