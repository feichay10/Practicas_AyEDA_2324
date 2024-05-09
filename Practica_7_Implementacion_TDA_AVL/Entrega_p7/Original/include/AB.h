/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzada
 * Curso: 2º
 * Práctica 7: Implementacion del TDA AVL
 * @file AB.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AB_H
#define AB_H

#include <iostream>
#include <queue>

#include "nodeB.h"
#include "colors.h"

/**
 * @brief Class AB that represents a binary tree
 * 
 * @tparam Key 
 */
template <class Key>
class AB {
 public:
  NodeB<Key>* getRoot() const;
  NodeB<Key>*& getRoot();
  void setRoot(NodeB<Key>* root);
  int getNumNodes() const;

  // Methods
  virtual bool insert(const Key& k) = 0;
  virtual bool search(const Key& k) const = 0;
  virtual bool remove(const Key& k) = 0;

  // Tour methods
  void inorder() const;
  void inorder(NodeB<Key>* node) const;
  void preorder() const;
  void preorder(NodeB<Key>* node) const;
  void postorder() const;
  void postorder(NodeB<Key>* node) const;
  void byLevel() const;
  void byLevel(NodeB<Key>* node) const;

  // Other methods
  int height() const;
  int heightN(NodeB<Key>* node) const;
  bool empty();
  int getLeafCount() const;
  int countLeafNodes(NodeB<Key>* node) const;

  virtual void write(std::ostream& os) const;
  friend std::ostream& operator<<(std::ostream& os, const AB<Key>& ab) {
    ab.write(os);
    return os;
  }

 protected:
  NodeB<Key>* root_;
  int numNodes_ = 0;
};

/**
 * @brief Get a pointer to the root node of the binary tree.
 * 
 * @tparam Key 
 * @return NodeB<Key>* 
 */
template <class Key>
NodeB<Key>* AB<Key>::getRoot() const {
  return root_;
}

/**
 * @brief Get a reference to a pointer to the root node of the binary tree
 * 
 * @tparam Key 
 * @return NodeB<Key>*& 
 */
template <class Key>
NodeB<Key>*& AB<Key>::getRoot() {
  return root_;
}

/**
 * @brief Set the root node of the binary tree
 * 
 * @tparam Key 
 * @param root 
 */
template <class Key>
void AB<Key>::setRoot(NodeB<Key>* root) {
  root_ = root;
}

/**
 * @brief Get the number of nodes in the binary tree
 * 
 * @tparam Key 
 * @return int 
 */
template <class Key>
int AB<Key>::getNumNodes() const {
  return numNodes_;
}

/**
 * @brief Inorder traversal of the binary tree
 * 
 * @tparam Key 
 */
template <class Key>
void AB<Key>::inorder() const {
  inorder(root_);
}

/**
 * @brief Inorder traversal of the binary tree
 * 
 * @tparam Key 
 * @param node 
 */
template <class Key>
void AB<Key>::inorder(NodeB<Key>* node) const {
  if (node != nullptr) {
    inorder(node->getLeft());
    std::cout << BLUE_BOLD << node->getData() << " " << RESET;
    inorder(node->getRight());
  }
}

/**
 * @brief Preorder traversal of the binary tree
 * 
 * @tparam Key 
 */
template <class Key>
void AB<Key>::preorder() const {
  preorder(root_);
}

/**
 * @brief Preorder traversal of the binary tree
 * 
 * @tparam Key 
 * @param node 
 */
template <class Key>
void AB<Key>::preorder(NodeB<Key>* node) const {
  if (node != nullptr) {
    std::cout << BLUE_BOLD << node->getData() << " " << RESET;
    preorder(node->getLeft());
    preorder(node->getRight());
  }
}

/**
 * @brief Postorder traversal of the binary tree
 * 
 * @tparam Key 
 */
template <class Key>
void AB<Key>::postorder() const {
  postorder(root_);
}

/**
 * @brief Postorder traversal of the binary tree
 * 
 * @tparam Key 
 * @param node 
 */
template <class Key>
void AB<Key>::postorder(NodeB<Key>* node) const {
  if (node != nullptr) {
    postorder(node->getLeft());
    postorder(node->getRight());
    std::cout << BLUE_BOLD << node->getData() << " " << RESET;
  }
}

/**
 * @brief Level order traversal of the binary tree
 * 
 * @tparam Key 
 */
template <class Key>
void AB<Key>::byLevel() const {
  byLevel(root_);
}

/**
 * @brief Level order traversal of the binary tree
 * 
 * @tparam Key 
 * @param node 
 */
template <class Key>
void AB<Key>::byLevel(NodeB<Key>* node) const {
  std::queue<NodeB<Key>*> queue;
  queue.push(node);
  while (!queue.empty()) {
    if (queue.front() != nullptr) {
      std::cout << BLUE_BOLD << queue.front()->getData() << " " << RESET;
      queue.push(queue.front()->getLeft());
      queue.push(queue.front()->getRight());
    }
    queue.pop();
  }
}

/**
 * @brief Get the height of the binary tree
 * 
 * @tparam Key 
 * @return int 
 */
template <class Key>
int AB<Key>::height() const {
  return heightN(root_);
}

/**
 * @brief Get the height of the binary tree
 * 
 * @tparam Key 
 * @param node 
 * @return int 
 */
template <class Key>
int AB<Key>::heightN(NodeB<Key>* node) const {
  if (node == nullptr) {
    return 0;
  } else {
    int leftHeight = heightN(node->getLeft());
    int rightHeight = heightN(node->getRight());

    if (leftHeight > rightHeight) {
      return leftHeight + 1;
    } else {
      return rightHeight + 1;
    }
  }
}

/**
 * @brief Check if the binary tree is empty
 * 
 * @tparam Key 
 * @return true 
 * @return false 
 */
template <class Key>
bool AB<Key>::empty() {
  return root_ == nullptr;
}

/**
 * @brief Get the number of leaf nodes in the binary tree
 * 
 * @tparam Key 
 * @return int 
 */
template <class Key>
int AB<Key>::getLeafCount() const {
  return countLeafNodes(root_);
}

/**
 * @brief Count the number of leaf nodes in the binary tree
 * 
 * @tparam Key 
 * @param node 
 * @return int 
 */
template <class Key>
int AB<Key>::countLeafNodes(NodeB<Key>* node) const {
  if (node == nullptr) {
    return 0;
  }
  if (node->getLeft() == nullptr && node->getRight() == nullptr) {
    return 1;
  }
  return countLeafNodes(node->getLeft()) + countLeafNodes(node->getRight());
}

/**
 * @brief Write the binary tree to an output stream
 * 
 * @tparam Key 
 * @param os 
 */
template <class Key>
void AB<Key>::write(std::ostream& os) const {
  int k = 0;
  std::queue<NodeB<Key>*> queue, queueAux;
  queue.push(root_);
  while (!queue.empty()) {
    os << "Level " << k << ": ";
    while (!queue.empty()) {
      if (queue.front() != nullptr) {
        os << "[" << queue.front()->getData() << "] ";
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
    os << std::endl;
    k++;
  }
}

#endif  // AB_H