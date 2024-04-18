/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 7: Implementacion del TDA AVL
 * @file nodeB.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NODEB_H_
#define NODEB_H_

template <class Key>
class NodeB {
 public:
  NodeB(Key data_, NodeB<Key>* left_ = nullptr, NodeB<Key>* right_ = nullptr) : data_(data_), left_(left_), right_(right_) {}
  
  Key getData() const;
  void setData(Key data);
  NodeB<Key>* getLeft() const;
  NodeB<Key>*& getLeft();
  NodeB<Key>* getRight() const;
  NodeB<Key>*& getRight();
  void setLeft(NodeB<Key>* left);
  void setRight(NodeB<Key>* right);

 protected:
  Key data_;
  NodeB<Key>* left_;
  NodeB<Key>* right_;
};

template <class Key>
Key NodeB<Key>::getData() const {
  return data_;
}

template <class Key>
void NodeB<Key>::setData(Key data) {
  NodeB::data_ = data;
}

template <class Key>
NodeB<Key>* NodeB<Key>::getLeft() const {
  return left_;
}

template <class Key>
NodeB<Key>*& NodeB<Key>::getLeft() {
  return left_;
}

template <class Key>
NodeB<Key>* NodeB<Key>::getRight() const {
  return right_;
}

template <class Key>
NodeB<Key>*& NodeB<Key>::getRight() {
  return right_;
}

template <class Key>
void NodeB<Key>::setLeft(NodeB<Key>* left) {
  left_ = left;
}

template <class Key>
void NodeB<Key>::setRight(NodeB<Key>* right) {
  right_ = right;
}

#endif  // NODEB_H_