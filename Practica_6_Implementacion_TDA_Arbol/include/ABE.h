/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 6: Implementacion del TDA Árbol
 * @file ABE.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ABE_H
#define ABE_H

#include "AB.h"

template<class Key>
class ABE : public AB<Key> {
 public:
  bool insert(const Key& k) override;
  bool search(const Key& k) const override;
  void inorder() const override;
  bool empty() override;
};

template<class Key>
bool ABE<Key>::insert(const Key& k) {
  return true;
}



template<class Key>
bool ABE<Key>::search(const Key& k) const {
  return false;
}

template<class Key>
void ABE<Key>::inorder() const {
  return;
}

template<class Key>
bool ABE<Key>::empty() {
  return AB<Key>::getRoot() == nullptr;
}

#endif // ABE_H