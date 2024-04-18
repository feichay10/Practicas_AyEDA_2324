/**
 * @file ABLevel.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef ABLEVEL_H
#define ABLEVEL_H

#include <iostream>

#include "AB.h"

template <class Key>
class ABLevel : public AB<Key> {
 public:
  bool insert(const Key& k) override;
  bool search(const Key& k) const override { return false; }
  bool remove(const Key& k) override { return false; }
};

template <class Key>
bool ABLevel<Key>::insert(const Key& k) {
  NodeB<Key>* newNode = new NodeB<Key>(k);
  if (!newNode) return false;

  if (!AB<Key>::getRoot()) {
    AB<Key>::setRoot(newNode);
    return true;
  }

  std::queue<NodeB<Key>*> q;
  q.push(AB<Key>::getRoot());

  while (!q.empty()) {
    NodeB<Key>* node = q.front();
    q.pop();

    if (!node->getLeft()) {
      node->setLeft(newNode);
      return true;
    } else {
      q.push(node->getLeft());
    }

    if (!node->getRight()) {
      node->setRight(newNode);
      return true;
    } else {
      q.push(node->getRight());
    }
  }

  return false;
}

#endif // ABLEVEL_H