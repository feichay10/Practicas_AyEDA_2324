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
#include "NodeAVL.h"

template <class Key>
class AVL : public ABB<Key> {
 public:
  AVL(bool trace = false, NodeAVL<Key>* node = nullptr);
  bool insert(const Key& data) override;

  void setRoot(NodeAVL<Key>* root);
  NodeAVL<Key>*& getRoot();
  NodeAVL<Key>* getRoot() const;

  void setTrace(bool trace);
  void write(std::ostream& os) const;

 private:
  bool trace_ = false;

  void insertBalance(NodeAVL<Key>*& root, NodeAVL<Key>*& newOne, bool& grow);
  void insertRebalanceLeft(NodeAVL<Key>*& root, bool& grow);
  void insertRebalanceRight(NodeAVL<Key>*& root, bool& grow);

  void rotation_II(NodeAVL<Key>*& node);
  void rotation_DD(NodeAVL<Key>*& node);
  void rotation_ID(NodeAVL<Key>*& node);
  void rotation_DI(NodeAVL<Key>*& node);
};

template <class Key>
AVL<Key>::AVL(bool trace, NodeAVL<Key>* node) {
  this->trace_ = trace;
  this->AB<Key>::setRoot(node);
}

template <class Key>
void AVL<Key>::setRoot(NodeAVL<Key>* root) {
  this->AB<Key>::setRoot(root);
}

template <class Key>
NodeAVL<Key>*& AVL<Key>::getRoot() {
  return reinterpret_cast<NodeAVL<Key>*&>(this->AB<Key>::getRoot());
}

template <class Key>
NodeAVL<Key>* AVL<Key>::getRoot() const {
  return reinterpret_cast<NodeAVL<Key>*>(this->AB<Key>::getRoot());
}

template <class Key>
void AVL<Key>::setTrace(bool trace) {
  this->trace_ = trace;
}

template <class Key>
void AVL<Key>::write(std::ostream& os) const {
  int k = 0;
  std::queue<NodeB<Key>*> queue, queueAux;
  queue.push(this->getRoot());
  while (!queue.empty()) {
    os << "Level " << k << ": ";
    while (!queue.empty()) {
      if (queue.front() != nullptr) {
        os << "[" << queue.front()->getData();
        if (this->trace_) {
          os << " (" << static_cast<NodeAVL<Key>*>(queue.front())->getBalance() << ")";
        }
        os << "] ";
        queueAux.push(queue.front()->getLeft());
        queueAux.push(queue.front()->getRight());
      } else {
        os << "[.] ";
      }
      queue.pop();
    }
    queue = queueAux;
    while (!queueAux.empty()) {
      queueAux.pop();
    }
    k++;
    os << "\n";
  }
}

template <class Key>
bool AVL<Key>::insert(const Key& data) {
  if (this->search(data)) {
    return false;
  }

  NodeAVL<Key>* newOne = new NodeAVL<Key>(data);
  bool grow = false;
  this->insertBalance(this->getRoot(), newOne, grow);
  return true;
}

template <class Key>
void AVL<Key>::insertBalance(NodeAVL<Key>*& root, NodeAVL<Key>*& newOne, bool& grow) {
  if (root == nullptr) {
    root = newOne;
    grow = true;
  } else if (newOne->getData() < root->getData()) { // Insertar balanceado por la izquierda
    insertBalance(reinterpret_cast<NodeAVL<Key>*&>(root->getLeft()), newOne, grow);
    if (grow) {
      insertRebalanceLeft(root, grow);
    }
  } else if (newOne->getData() > root->getData()) { // Insertar balanceado por la derecha
    insertBalance(reinterpret_cast<NodeAVL<Key>*&>(root->getRight()), newOne, grow);
    if (grow) {
      insertRebalanceRight(root, grow);
    }
  }
}

template <class Key>
void AVL<Key>::insertRebalanceLeft(NodeAVL<Key>*& root, bool& grow) {
  switch (root->getBalance()) {
    case -1:
      root->setBalance(0);
      grow = false;
      break;
    case 0:
      root->setBalance(1);
      break;
    case 1:
      if (this->trace_) {
        std::cout << "Desbalanceo: " << std::endl;
        this->write(std::cout);
      }
      NodeAVL<Key>* node1 = reinterpret_cast<NodeAVL<Key>*&>(root->getLeft());
      if (node1->getBalance() == 1) {
        rotation_II(root);
      } else {
        rotation_ID(root);
      }
      grow = false;
  }
}

template <class Key>
void AVL<Key>::insertRebalanceRight(NodeAVL<Key>*& root, bool& grow) {
  switch (root->getBalance()) {
    case 1:
      root->setBalance(0);
      grow = false;
      break;
    case 0:
      root->setBalance(-1);
      break;
    case -1:
      if (this->trace_) {
        std::cout << "Desbalanceo: " << std::endl;
        this->write(std::cout);
      }
      NodeAVL<Key>* node1 = reinterpret_cast<NodeAVL<Key>*&>(root->getRight());
      if (node1->getBalance() == -1) {
        rotation_DD(root);
      } else {
        rotation_DI(root);
      }
      grow = false;
  }
}

template <class Key>
void AVL<Key>::rotation_II(NodeAVL<Key>*& node) {
  if (this->trace_) {
    std::cout << "Rotation II on [" << node->getData() << " (" <<  node->getBalance() << ")]" << std::endl;
  }
  NodeAVL<Key>* node1 = reinterpret_cast<NodeAVL<Key>*&>(node->getLeft());
  node->setLeft(reinterpret_cast<NodeAVL<Key>*&>(node1->getRight()));
  node1->setRight(node);
  if (node1->getBalance() == 1) {
    node->setBalance(0);
    node1->setBalance(0);
  } else {
    node->setBalance(1);
    node1->setBalance(-1);
  }
  node = node1;
}

template <class Key>
void AVL<Key>::rotation_DD(NodeAVL<Key>*& node) {
  if (this->trace_) {
    std::cout << "Rotation DD on [" << node->getData() << "]" << std::endl;
  }
  NodeAVL<Key>* node1 = reinterpret_cast<NodeAVL<Key>*&>(node->getRight());
  node->setRight(reinterpret_cast<NodeAVL<Key>*&>(node1->getLeft()));
  node1->setLeft(node);
  if (node1->getBalance() == -1) {
    node->setBalance(0);
    node1->setBalance(0);
  } else {
    node->setBalance(-1);
    node1->setBalance(1);
  }
  node = node1;
}

template <class Key>
void AVL<Key>::rotation_ID(NodeAVL<Key>*& node) {
  if (this->trace_) {
    std::cout << "Rotation ID on [" << node->getData() << "]" << std::endl;
  }
  NodeAVL<Key>* node1 = node->getLeft();
  NodeAVL<Key>* node2 = node1->getRight();
  node->getLeft() = node2->getRight();
  node2->setRight(node);
  node1->setRight(node2->getLeft());
  node2->getLeft() = node1;
  if (node2->getBalance() == -1) {
    node->setBalance(1);
  } else {
    node->setBalance(0);
  }
  if (node2->getBalance() == 1) {
    node1->setBalance(-1);
  } else {
    node1->setBalance(0);
  }
  node2->setBalance(0);
  node = node2;
}

template <class Key>
void AVL<Key>::rotation_DI(NodeAVL<Key>*& node) {
  if (this->trace_) {
    std::cout << "Rotation DI on [" << node->getData() << "]" << std::endl;
  }
  NodeAVL<Key>* node1 = node->getRight();
  NodeAVL<Key>* node2 = node1->getLeft();
  node->getRight() = node2->getLeft();
  node2->setLeft(node);
  node1->setLeft(node2->getRight());
  node2->setRight(node1);
  if (node2->getBalance() == 1) {
    node1->setBalance(-1);
  } else {
    node1->setBalance(-1);
  }
  if (node2->getBalance() == -1) {
    node->setBalance(1);
  } else {
    node->setBalance(0);
  }
  node2->setBalance(0);
  node = node2;
}

#endif  // AVL_H