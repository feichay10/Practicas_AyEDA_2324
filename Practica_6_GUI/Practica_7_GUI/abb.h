#ifndef ABB_H
#define ABB_H

#include <iostream>
#include <queue>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QFont>
#include <QVector>

#include "nodeB.h"

template <class Key>
class ABB {
 public:
    NodeB<Key>* getRoot() const;
    NodeB<Key>*& getRoot();
    void setRoot(NodeB<Key>* root);

    bool insert(const Key& k);
    bool search(const Key& k) const;
    bool remove(const Key& k);

    // Other methods
    bool empty();

    void write(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const ABB<Key>& ab) {
        ab.write(os);
        return os;
    }

 private:
    NodeB<Key>* root_;

    bool insertBranch(NodeB<Key>*& node, Key k);
    bool searchBranch(NodeB<Key>* node, Key k) const;
    bool removeBranch(NodeB<Key>*& node, Key k);
    bool replace(NodeB<Key>*& deleteNode, NodeB<Key>*& substituteNode);
};

template <class Key>
NodeB<Key>* ABB<Key>::getRoot() const {
    return root_;
}

template <class Key>
NodeB<Key>*& ABB<Key>::getRoot() {
    return root_;
}

template <class Key>
void ABB<Key>::setRoot(NodeB<Key>* root) {
    root_ = root;
}

template <class Key>
bool ABB<Key>::insert(const Key& k) {
    if (search(k)) {
        return false;
    }

    if (this->getRoot() == nullptr) {
        root_ = new NodeB<Key>(k);
        return true;
    } else {
        return insertBranch(root_, k);
    }
}

template <class Key>
bool ABB<Key>::insertBranch(NodeB<Key>*& node, Key k) {
    if (node == nullptr) {
        node = new NodeB<Key>(k);
    } else if (k < node->getData()) {
        insertBranch(node->getLeft(), k);
    } else {
        insertBranch(node->getRight(), k);
    }
    return true;
}

template <class Key>
bool ABB<Key>::search(const Key& k) const {
    return searchBranch(root_, k);
}

template <class Key>
bool ABB<Key>::searchBranch(NodeB<Key>* node, Key k) const {
    if (node == nullptr) {
        return false;
    }
    if (k == node->getData()) {
        return true;
    }
    if (k < node->getData()) {
        return searchBranch(node->getLeft(), k);
    }
    return searchBranch(node->getRight(), k);
}

template <class Key>
bool ABB<Key>::remove(const Key& k) {
    if (!search(k)) {
        return false;
    }

    return removeBranch(root_, k);
}

template <class Key>
bool ABB<Key>::removeBranch(NodeB<Key>*& node, Key k) {
    if (node == nullptr) {
        return false;
    }
    if (k < node->getData()) {
        return removeBranch(node->getLeft(), k);
    } else if (k > node->getData()) {
        return removeBranch(node->getRight(), k);
    } else {  // k == node->getData()
        NodeB<Key>* deleteNode = node;
        if (node->getRight() == nullptr) {
            node = node->getLeft();
        } else if (node->getLeft() == nullptr) {
            node = node->getRight();
        } else {
            replace(deleteNode, node->getLeft());
        }
        delete deleteNode;
    }
    return true;
}

template <class Key>
bool ABB<Key>::replace(NodeB<Key>*& deleteNode, NodeB<Key>*& substituteNode) {
    if (substituteNode->getRight() != nullptr) {
        replace(deleteNode, substituteNode->getRight());
    } else {
        deleteNode->setData(substituteNode->getData());
        deleteNode = substituteNode;
        substituteNode = substituteNode->getLeft();
    }
    return true;
}

template <class Key>
bool ABB<Key>::empty() {
    return root_ == nullptr;
}

template <class Key>
void ABB<Key>::write(std::ostream& os) const {
    int k = 0;
    std::queue<NodeB<Key>*> queue, queueAux;
    queue.push(root_);
    while (!queue.empty()) {
        os << "Level " << k << ": ";
        while (!queue.empty()) {
            if (queue.front() != nullptr) {
                os << "[" << queue.front()->getData() << "]";
                queueAux.push(queue.front()->getLeft());
                queueAux.push(queue.front()->getRight());
            } else {
                os << "[.]";
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

template <class Key>
void ABB<Key>::drawTree(QGraphicsScene* scene, QGraphicsView* view) const {
    if (!root_) return;

    const int nodeRadius = 30;
    const int spacing = 50;
    const int levelHeight = 100;
    const int xOffset = 50; // Incremento horizontal para separar nodos padres con dos hijos

    std::map<NodeB<Key>*, int> nodeXPositions; // Mapa para mantener las posiciones horizontales de los nodos

    std::queue<std::tuple<NodeB<Key>*, int, int>> queue; // Cola para el recorrido BFS
    queue.push({root_, view->width() / 2, 0});

    while (!queue.empty()) {
        auto [node, parentX, level] = queue.front();
        queue.pop();

        // Calcular la posición horizontal (x) del nodo
        int childrenCount = (node->getLeft() ? 1 : 0) + (node->getRight() ? 1 : 0);
        int x;
        if (childrenCount == 0) {
            // Nodo hoja
            x = parentX;
        } else if (childrenCount == 1) {
            // Un solo hijo
            x = parentX;
        } else {
            // Dos hijos
            x = parentX;
            parentX += (node->getLeft() ? -xOffset : xOffset); // Ajustar el nodo padre
        }

        // Calcular la posición vertical (y) del nodo
        int y = levelHeight * (level + 1);

        // Ajustar la posición vertical si hay superposición con otro nodo en la misma posición
        while (nodeXPositions.find(node) != nodeXPositions.end() && x == nodeXPositions[node]) {
            y += nodeRadius * 2;
        }

        // Dibujar el nodo como un círculo
        QGraphicsEllipseItem* ellipse = scene->addEllipse(x - nodeRadius, y - nodeRadius, 2 * nodeRadius, 2 * nodeRadius);
        QGraphicsTextItem* text = scene->addText(QString::number(node->getData()));
        text->setPos(x - nodeRadius / 2, y - nodeRadius / 2);

        // Agregar líneas para conectar con los nodos hijos si existen
        if (node->getLeft()) {
            queue.push({node->getLeft(), x, level + 1});
            int childX = x - spacing / 2;
            int childY = y + levelHeight;
            scene->addLine(x - nodeRadius, y, childX + nodeRadius, childY); // Línea adicional
            scene->addLine(childX + nodeRadius, childY, childX + nodeRadius, childY - nodeRadius); // Línea adicional
            scene->addLine(childX + nodeRadius, childY - nodeRadius, childX, childY - nodeRadius); // Línea adicional
        }
        if (node->getRight()) {
            queue.push({node->getRight(), x, level + 1});
            int childX = x + spacing / 2;
            int childY = y + levelHeight;
            scene->addLine(x + nodeRadius, y, childX - nodeRadius, childY); // Línea adicional
            scene->addLine(childX - nodeRadius, childY, childX - nodeRadius, childY - nodeRadius); // Línea adicional
            scene->addLine(childX - nodeRadius, childY - nodeRadius, childX, childY - nodeRadius); // Línea adicional
        }

        // Dibujar la línea principal que conecta los centros de los círculos
        if (node->getLeft())
            scene->addLine(x, y, x - spacing / 2, y + levelHeight);
        if (node->getRight())
            scene->addLine(x, y, x + spacing / 2, y + levelHeight);

        // Registrar la posición horizontal del nodo para evitar superposiciones
        nodeXPositions[node] = x;
    }

    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}



#endif  // ABB_H
