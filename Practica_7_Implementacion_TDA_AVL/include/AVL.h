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
#include "nodeAVL.h"

template <class Key>
class AVL : public ABB<Key> {
 public:
  bool insert(const Key& k) override;

 private:
  bool trace_ = false;

  void insertBalance(NodeAVL<Key>*& root, NodeAVL<Key>*& newNode, bool& grow);
  void insertRebalanceLeft(NodeAVL<Key>*& node, bool& grow);
  void insertRebalanceRight(NodeAVL<Key>*& node, bool& grow);

  void rotationII(NodeAVL<Key>*& node);
  void rotationID(NodeAVL<Key>*& node);
  void rotationDI(NodeAVL<Key>*& node);
  void rotationDD(NodeAVL<Key>*& node);
};

template <class Key>
bool AVL<Key>::insert(const Key& k) {
  NodeAVL<Key>* newNode = new NodeAVL<Key>(k);
  bool grow = false;
  NodeAVL<Key>* rootAVL = static_cast<NodeAVL<Nif>*>(this->root_);
  insertBalance(rootAVL, newNode, grow);
  return grow;
}

template <class Key>
void AVL<Key>::insertBalance(NodeAVL<Key>*& root, NodeAVL<Key>*& newNode, bool& grow) {
  if (root == nullptr) {
    root = newNode;
    grow = true;
  } else if (newNode->getData() < root->getData()) {
    insertBalance(root->getLeft(), newNode, grow);
    if (grow) {
      insertRebalanceLeft(root, grow);
    }
  } else {
    insertBalance(root->getRight(), newNode, grow);
    if (grow) {
      insertRebalanceRight(root, grow);
    }
  }
}

template <class Key>
void AVL<Key>::insertRebalanceLeft(NodeAVL<Key>*& node, bool& grow) {
  switch (node->getBalance()) {
    case -1:
      node->setBalance(0);
      grow = false;
      break;
    case 0:
      node->setBalance(1);
      break;
    case 1:
      NodeAVL<Key>* node1 = node->getLeft();
      if (node1->getBalance() == 1) {
        rotationII(node);
      } else {
        rotationID(node);
      }
      grow = false;
      break;
  }
}

template <class Key>
void AVL<Key>::insertRebalanceRight(NodeAVL<Key>*& node, bool& grow) {
  switch (node->getBalance()) {
    case 1:
      node->setBalance(0);
      grow = false;
      break;
    case 0:
      node->setBalance(-1);
      break;
    case -1:
      NodeAVL<Key>* node1 = node->getRight();
      if (node1->getBalance() == -1) {
        rotationDD(node);
      } else {
        rotationDI(node);
      }
      grow = false;
      break;
  }
}

template <class Key>
void AVL<Key>::rotationII(NodeAVL<Key>*& node) {
  NodeAVL<Key>* node1 = node->getLeft();
  node->setLeft(node1->getRight());
  node1->setRight(node);
  node = node1;
  if (node->getBalance() == 1) {
    node->setBalance(0);
    node1->setBalance(0);
  } else { // node->getBalance() == 0
    node->setBalance(1);
    node1->setBalance(-1);
  }
  node = node1;
}

template <class Key>
void AVL<Key>::rotationID(NodeAVL<Key>*& node) {
  NodeAVL<Key>* node1 = node->getLeft();
  NodeAVL<Key>* node2 = node1->getRight();
  node->setLeft(node2->getRight());
  node2->setRight(node);
  node1->setRight(node2->getLeft());
  node2->setLeft(node1);
  if (node2->getBalance() == -1) {
    node1->setBalance(1);
  } else {
    node1->setBalance(0);
  }
  if (node2->getBalance() == 1) {
    node->setBalance(-1);
  } else {
    node->setBalance(0);
  }
  node2->setBalance(0);
  node = node2;
}

template <class Key>
void AVL<Key>::rotationDI(NodeAVL<Key>*& node) {
  NodeAVL<Key>* node1 = node->getRight();
  NodeAVL<Key>* node2 = node1->getLeft();
  node->setRight(node2->getLeft());
  node2->setLeft(node);
  node1->setLeft(node2->getRight());
  node2->setRight(node1);
  if (node2->getBalance() == 1) {
    node1->setBalance(-1);
  } else {
    node1->setBalance(0);
  }
  if (node2->getBalance() == -1) {
    node->setBalance(1);
  } else {
    node->setBalance(0);
  }
  node2->setBalance(0);
  node = node2;
}

template <class Key>
void AVL<Key>::rotationDD(NodeAVL<Key>*& node) {
  NodeAVL<Key>* node1 = node->getRight();
  node->setRight(node1->getLeft());
  node1->setLeft(node);
  if (node->getBalance() == -1) {
    node->setBalance(0);
    node1->setBalance(0);
  } else { // node1->getBalance() == 0
    node->setBalance(-1);
    node1->setBalance(1);
  }
  node = node1;
}


#endif  // AVL_H