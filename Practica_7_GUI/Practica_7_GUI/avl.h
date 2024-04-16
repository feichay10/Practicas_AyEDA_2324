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

#include "abb.h"
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

    void removeBranch(NodeAVL<Key>*& node, const Key& k, bool& decrease);
    bool replace(NodeAVL<Key>*& deleteNode, NodeAVL<Key>*& substituteNode, bool& decrease);
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
bool AVL<Key>::insert(const Key& k) {
    if (this->search(k)) {
        return false;
    }

    NodeAVL<Key>* newOne = new NodeAVL<Key>(k);
    bool grow = false;
    this->insertBalance(this->getRoot(), newOne, grow);
    return true;
}

template <class Key>
bool AVL<Key>::remove(const Key& k) {
    if (!this->search(k)) {
        return false;
    }

    bool decrease = false;
    removeBranch(this->getRoot(), k, decrease);
    return true;
}

template <class Key>
void AVL<Key>::write(std::ostream& os) const {
    int k = 0;
    std::queue<NodeAVL<Key>*> queue, queueAux;
    queue.push(this->getRoot());
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
void AVL<Key>::insertBalance(NodeAVL<Key>*& root, NodeAVL<Key>* newOne, bool& grow) {
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
void AVL<Key>::removeBranch(NodeAVL<Key>*& node, const Key& k, bool& decrease) {
    if (node == nullptr) {
        return;
    }

    if (k < node->getData()) {
        removeBranch(reinterpret_cast<NodeAVL<Key>*&>(node->getLeft()), k, decrease);
        if (decrease) {
            removeRebalanceLeft(node, decrease);
        }
    } else if (k > node->getData()) {
        removeBranch(reinterpret_cast<NodeAVL<Key>*&>(node->getRight()), k, decrease);
        if (decrease) {
            removeRebalanceRight(node, decrease);
        }
    } else {
        NodeAVL<Key>* deleteNode = node;
        if (node->getLeft() == nullptr) {
            node = reinterpret_cast<NodeAVL<Key>*>(node->getRight());
            decrease = true;
        } else if (node->getRight() == nullptr) {
            node = reinterpret_cast<NodeAVL<Key>*>(node->getLeft());
            decrease = true;
        } else {
            replace(deleteNode, reinterpret_cast<NodeAVL<Key>*&>(node->getLeft()), decrease);
            if (decrease) {
                removeRebalanceLeft(node, decrease);
            }
        }
        delete deleteNode;
    }
}

template <class Key>
bool AVL<Key>::replace(NodeAVL<Key>*& deleteNode, NodeAVL<Key>*& substituteNode, bool& decrease) {
    if (substituteNode->getRight() != nullptr) {
        replace(deleteNode, reinterpret_cast<NodeAVL<Key>*&>(substituteNode->getRight()), decrease);
        if (decrease) {
            removeRebalanceRight(substituteNode, decrease);
        }
    } else {
        deleteNode->setData(substituteNode->getData());
        deleteNode = substituteNode;
        substituteNode = reinterpret_cast<NodeAVL<Key>*>(substituteNode->getLeft());
        decrease = true;
    }

    return true;
}

template <class Key>
void AVL<Key>::removeRebalanceLeft(NodeAVL<Key>*& node, bool& decrease) {
    switch (node->getBalance()) {
    case -1: {
        NodeAVL<Key>* node1 = reinterpret_cast<NodeAVL<Key>*&>(node->getRight());
        if (node1->getBalance() > 0) {
            rotation_DI(node);
        } else {
            if (node1->getBalance() == 0) {
                decrease = false;
            }
            rotation_DD(node);
            break;
        }
    }
    case 0:
        node->setBalance(-1);
        decrease = false;
        break;
    case 1:
        node->setBalance(0);
    }
}

template <class Key>
void AVL<Key>::removeRebalanceRight(NodeAVL<Key>*& node, bool& decrease) {
    switch (node->getBalance()) {
    case 1: {
        NodeAVL<Key>* node1 = reinterpret_cast<NodeAVL<Key>*&>(node->getLeft());
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
    }
}

template <class Key>
void AVL<Key>::rotation_II(NodeAVL<Key>*& node) {
    if (this->trace_) {
        std::cout << "Rotation II on [" << node->getData() << " (" << AB<Key>::heightN(node->getLeft()) - AB<Key>::heightN(node->getRight()) << ")]" << std::endl;
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
        std::cout << "Rotation DD on [" << node->getData() << " (" << AB<Key>::heightN(node->getLeft()) - AB<Key>::heightN(node->getRight()) << ")]" << std::endl;
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
