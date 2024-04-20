/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementacion del TDA Árbol 
 * @file nodeB.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef NODEB_H_
#define NODEB_H_

/**
 * @brief Class NodeB that represents a node of a binary tree
 * 
 * @tparam Key 
 */
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

/**
 * @brief Get the Data object
 * 
 * @tparam Key 
 * @return Key 
 */
template <class Key>
Key NodeB<Key>::getData() const {
  return data_;
}

/**
 * @brief Set the Data object
 * 
 * @tparam Key 
 * @param data 
 */
template <class Key>
void NodeB<Key>::setData(Key data) {
  NodeB::data_ = data;
}

/**
 * @brief Get a pointer to the left node of the current binary node.
 * 
 * @tparam Key 
 * @return NodeB<Key>* 
 */
template <class Key>
NodeB<Key>* NodeB<Key>::getLeft() const {
  return left_;
}

/**
 * @brief Get a reference to a pointer to the left node of the current binary node.
 * 
 * @tparam Key 
 * @return NodeB<Key>*& 
 */
template <class Key>
NodeB<Key>*& NodeB<Key>::getLeft() {
  return left_;
}

/**
 * @brief Get a pointer to the right node of the current binary node.
 * 
 * @tparam Key 
 * @return NodeB<Key>* 
 */
template <class Key>
NodeB<Key>* NodeB<Key>::getRight() const {
  return right_;
}

/**
 * @brief Get a reference to a pointer to the right node of the current binary node.
 * 
 * @tparam Key 
 * @return NodeB<Key>*& 
 */
template <class Key>
NodeB<Key>*& NodeB<Key>::getRight() {
  return right_;
}

/**
 * @brief Set the left node of the current binary node.
 * 
 * @tparam Key 
 * @param left 
 */
template <class Key>
void NodeB<Key>::setLeft(NodeB<Key>* left) {
  left_ = left;
}

/**
 * @brief Set the right node of the current binary node.
 * 
 * @tparam Key 
 * @param right 
 */
template <class Key>
void NodeB<Key>::setRight(NodeB<Key>* right) {
  right_ = right;
}

#endif  // NODEB_H_