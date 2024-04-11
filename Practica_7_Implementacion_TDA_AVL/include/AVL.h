/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 7: Implementacion del TDA AVL
 * @file AVL.h
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

#include "ABB.h"

template <class Key>
class AVL : public ABB<Key> {
 public:
  bool insert(const Key& k) override;

 private:
  bool trace_ = false;
  void rotationII(NodeAVL<Key>*& node);
  void rotationID(NodeAVL<Key>*& node);
  void rotationDI(NodeAVL<Key>*& node);
  void rotationDD(NodeAVL<Key>*& node);
  void balance(NodeAVL<Key>*& node);
};

#endif  // AVL_H