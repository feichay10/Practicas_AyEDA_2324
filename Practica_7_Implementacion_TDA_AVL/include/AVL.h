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
  void setRoot(NodeAVL<Key>* root);
  NodeAVL<Key>*& getRoot();
  NodeAVL<Key>* getRoot() const;
  void setTrace(bool trace);

  bool insert(const Key& k) override;
  bool remove(const Key& k) override;

  void write(std::ostream& os) const;

 private:
  bool trace_ = false;

  void insertBalance(NodeAVL<Key>*& root, NodeAVL<Key>* newOne, bool& grow);
  void insertRebalanceLeft(NodeAVL<Key>*& root, bool& grow);
  void insertRebalanceRight(NodeAVL<Key>*& root, bool& grow);

  bool removeBranch(NodeAVL<Key>*& node, const Key& k, bool& decrease);
  void replace(NodeAVL<Key>*& deleteNode, NodeAVL<Key>*& substituteNode, bool& decrease);
  void removeRebalanceLeft(NodeAVL<Key>*& root, bool& decrease);
  void removeRebalanceRight(NodeAVL<Key>*& root, bool& decrease);

  void rotation_II(NodeAVL<Key>*& node);
  void rotation_DD(NodeAVL<Key>*& node);
  void rotation_ID(NodeAVL<Key>*& node);
  void rotation_DI(NodeAVL<Key>*& node);
};

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
  std::queue<NodeAVL<Key>*> queue, queueAux;
  queue.push(getRoot());
  while (!queue.empty()) {
    os << "Level " << k << ": ";
    while (!queue.empty()) {
      if (queue.front() != nullptr) {
        os << "[" << queue.front()->getData();
        if (trace_) {
          os << " (" <<  AB<Key>::heightN(queue.front()->getLeft()) - AB<Key>::heightN(queue.front()->getRight()) << ")";
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
bool AVL<Key>::insert(const Key& k) {
  if (this->search(k)) {
    return false;
  }

  this->numNodes_++;
  NodeAVL<Key>* newOne = new NodeAVL<Key>(k);
  bool grow = false;
  insertBalance(getRoot(), newOne, grow);
  return true;
}

template <class Key>
void AVL<Key>::insertBalance(NodeAVL<Key>*& root, NodeAVL<Key>* newOne, bool& grow) {
  if (root == nullptr) {
    root = newOne;
    grow = true;
  } else if (newOne->getData() < root->getData()) { // Insertar balanceado por la izquierda
    insertBalance(root->getLeft(), newOne, grow);
    if (grow) {
      insertRebalanceLeft(root, grow);
    }
  } else if (newOne->getData() > root->getData()) { // Insertar balanceado por la derecha
    insertBalance(root->getRight(), newOne, grow);
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
        write(std::cout);
      }
      NodeAVL<Key>* node1 = root->getLeft();
      if (node1->getBalance() == 1) {
        rotation_II(root);
      } else {
        rotation_ID(root);
      }
      grow = false;
      break;
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
        write(std::cout);
      }
      NodeAVL<Key>* node1 = root->getRight();
      if (node1->getBalance() == -1) {
        rotation_DD(root);
      } else {
        rotation_DI(root);
      }
      grow = false;
      break;
  }
}

template <class Key>
bool AVL<Key>::remove(const Key& k) {
  if (!this->search(k)) {
    return false;
  }

  this->numNodes_--;
  bool decrease = false;
  std::cout << getRoot()->getData() << std::endl;
  std::cout << k << std::endl;
  return removeBranch(getRoot(), k, decrease);
}

template <class Key>
bool  AVL<Key>::removeBranch(NodeAVL<Key>*& node, const Key& k, bool& decrease) {
  if (node == nullptr) {
    return false;
  }

  if (k < node->getData()) {
    // std::cout << "removeBranch: " << k << " < " << node->getData() << std::endl;
    removeBranch(node->getLeft(), k, decrease);
    if (decrease) {
      std::cout << "1 On RemoveBrancha calling Remove Rebalance Left: " << node->getData() << " - " << node->getBalance() << std::endl;
      removeRebalanceLeft(node, decrease);
    }
    return true;
  } else if (k > node->getData()) {
    // std::cout << "removeBranch: " << k << " > " << node->getData() << std::endl;
    removeBranch(node->getRight(), k, decrease);
    if (decrease) {
      removeRebalanceRight(node, decrease);
    }
    return true;
  } else {
    // std::cout << "removeBranch: " << k << " == " << node->getData() << std::endl;
    NodeAVL<Key>* deleteNode = node;
    if (node->getLeft() == nullptr) {
      node = node->getRight();
      decrease = true;
    } else if (node->getRight() == nullptr) {
      node = node->getLeft();
      decrease = true;
    } else { 
      replace(deleteNode, node->getLeft(), decrease);
      if (decrease) {
        std::cout << "2 On RemoveBrancha calling Remove Rebalance Left: " << node->getData() << " - " << node->getBalance() << std::endl;
        removeRebalanceLeft(node, decrease);
      }
    }
    delete deleteNode;
    return true;
  }

  return false;
}

template <class Key>
void AVL<Key>::replace(NodeAVL<Key>*& deleteNode, NodeAVL<Key>*& substituteNode, bool& decrease) {
  if (substituteNode->getRight() != nullptr) {
    replace(deleteNode, substituteNode->getRight(), decrease);
    if (decrease) {
      removeRebalanceRight(substituteNode, decrease);
    }
  } else {
    deleteNode->setData(substituteNode->getData());
    deleteNode = substituteNode;
    substituteNode = substituteNode->getLeft();
    decrease = true;
  }
}

template <class Key>
void AVL<Key>::removeRebalanceLeft(NodeAVL<Key>*& node, bool& decrease) {
  std::cout << "Remove Rebalance Left: " << node->getData() << " - " << node->getBalance() << std::endl;
  switch (node->getBalance()) {
    case -1: {
      NodeAVL<Key>* node1 = node->getRight();
      if (node1->getBalance() > 0) {
        rotation_DI(node);
      } else {
        if (node1->getBalance() == 0) {
          decrease = false;
        }
        rotation_DD(node);
      }
      break;
    }
    case 0:
      node->setBalance(-1);
      decrease = false;
      // rotation_DD(node);
      break;
    case 1:
      node->setBalance(0);
      break;
  }
}

template <class Key>
void AVL<Key>::removeRebalanceRight(NodeAVL<Key>*& node, bool& decrease) {
  switch (node->getBalance()) {
    case 1: {
        NodeAVL<Key>* node1 = node->getLeft();
        if (node1->getBalance() < 0) {
          rotation_ID(node);
        } else {
          if (node1->getBalance() == 0) {
            decrease = false;
          }
          rotation_II(node);
        }
        break;
      }
    case 0:
      node->setBalance(1);
      decrease = false;
      break;
    case -1:
      node->setBalance(0);
      break;
  }
}

template <class Key>
void AVL<Key>::rotation_II(NodeAVL<Key>*& node) {
  if (this->trace_) {
    std::cout << "Rotation II on [" << node->getData() << " (" << AB<Key>::heightN(node->getLeft()) - AB<Key>::heightN(node->getRight()) << ")]" << std::endl;
  }
  NodeAVL<Key>* node1 = node->getLeft();
  node->setLeft(node1->getRight());
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
    std::cout << "Rotation DD on [" << node->getData() << " (" << AB<Key>::heightN(node->getLeft()) - AB<Key>::heightN(node->getRight()) << ")]" << std::endl;
  }
  NodeAVL<Key>* node1 = node->getRight();
  node->setRight(node1->getLeft());
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
    std::cout << "Rotation ID on [" << node->getData() << " (" << AB<Key>::heightN(node->getLeft()) - AB<Key>::heightN(node->getRight()) << ")]" << std::endl;
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
    std::cout << "Rotation DI on [" << node->getData() << " (" << AB<Key>::heightN(node->getLeft()) - AB<Key>::heightN(node->getRight()) << ")]" << std::endl;
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