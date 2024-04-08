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

#ifndef NODEB_H
#define NODEB_H

#include <iostream>

template<class Key>
class NodeB {
 public:
  NodeB() = default;
  NodeB(Key key);
  NodeB(Key key, NodeB<Key>* left, NodeB<Key>* right);
  ~NodeB();

 private:
  Key data_;
  NodeB<Key>* left_;
  NodeB<Key>* right_;
};

#endif // NODEB_H