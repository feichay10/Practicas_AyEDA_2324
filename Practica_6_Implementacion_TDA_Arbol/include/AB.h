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

#include "nodeB.h"

template<class Key>
class AB {
 public:
  AB() = default;
  virtual ~AB() = default;

  virtual bool insert(const Key& k) = 0;
  virtual bool search(const Key& k) const = 0;
  virtual void inorden() const = 0;

  friend std::ostream& operator<<(std::ostream& os, const AB<Key>& ab);

 protected:
  NodeB<Key>* root_ = nullptr;
};

#endif // AB_H