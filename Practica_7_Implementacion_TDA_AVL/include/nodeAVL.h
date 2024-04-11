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

#ifndef AVL_H
#define AVL_H

#include "nodeB.h"

template <class Key>
class NodeAVL : public NodeB<Key> {
 public:
  NodeAVL(Key data, NodeAVL<Key>* left = nullptr, NodeAVL<Key>* right = nullptr);
  NodeAVL();
  ~NodeAVL() = default;

  int getBal() const;
  void setBal(int& bal);
  
  NodeAVL<Key>* getLeft() const;
  NodeAVL<Key>*& getLeft();
  NodeAVL<Key>* getRight() const;
  NodeAVL<Key>*& getRight();
  void setLeft(NodeAVL<Key>* left);
  void setRight(NodeAVL<Key>* right);
  void setData(Key data);
  Key getData() const;

 private:
  int bal_;
};

#endif // AVL_H