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

#include "AB.h"

template<class Key>
class ABB : public AB<Key> {
 public:
  ABB() = default;
  ~ABB() = default;

  bool insert(const Key& k) override;
  bool search(const Key& k) const override;
  void inorden() const override;
};

#endif // ABB_H