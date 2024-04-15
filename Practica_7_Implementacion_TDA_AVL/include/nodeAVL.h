/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 7: Implementacion del TDA AVL
 * @file nodeAVL.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NODEAVL_H
#define NODEAVL_H

#include "nodeB.h"

template <class Key>
class NodeAVL : public NodeB<Key> {
 public:
  NodeAVL();
  NodeAVL(Key data, NodeAVL<Key>* left = nullptr, NodeAVL<Key>* right = nullptr);
  ~NodeAVL() = default;

  int getBalance();
  void setBalance(const int& bal);
  
  NodeAVL<Key>* getLeft() const;
  NodeAVL<Key>*& getLeft();
  NodeAVL<Key>* getRight() const;
  NodeAVL<Key>*& getRight();
  void setLeft(NodeAVL<Key>* left);
  void setRight(NodeAVL<Key>* right);
  void setData(Key data);
  Key getData() const;

 private:
  int balance_;
};

template <class Key>
NodeAVL<Key>::NodeAVL() : NodeB<Key>(), balance_(0) {}

template <class Key>
NodeAVL<Key>::NodeAVL(Key data, NodeAVL<Key>* left, NodeAVL<Key>* right) : NodeB<Key>(data, left, right), balance_(0) {}

template <class Key>
int NodeAVL<Key>::getBalance() {
  return balance_;
}

template <class Key>
void NodeAVL<Key>::setBalance(const int& bal) {
  balance_ = bal;
}

template <class Key>
NodeAVL<Key>* NodeAVL<Key>::getLeft() const {
  return static_cast<NodeAVL<Key>*>(NodeB<Key>::getLeft());
}

template <class Key>
NodeAVL<Key>*& NodeAVL<Key>::getLeft() {
  return reinterpret_cast<NodeAVL<Key>*&>(NodeB<Key>::getLeft());
}

template <class Key>
NodeAVL<Key>* NodeAVL<Key>::getRight() const {
  return static_cast<NodeAVL<Key>*>(NodeB<Key>::getRight());
}

template <class Key>
NodeAVL<Key>*& NodeAVL<Key>::getRight() {
  return reinterpret_cast<NodeAVL<Key>*&>(NodeB<Key>::getRight());
}

template <class Key>
void NodeAVL<Key>::setLeft(NodeAVL<Key>* left) {
  NodeB<Key>::setLeft(left);
}

template <class Key>
void NodeAVL<Key>::setRight(NodeAVL<Key>* right) {
  NodeB<Key>::setRight(right);
}

template <class Key>
void NodeAVL<Key>::setData(Key data) {
  NodeB<Key>::setData(data);
}

template <class Key>
Key NodeAVL<Key>::getData() const {
  return NodeB<Key>::getData();
}

#endif // NODEAVL_H