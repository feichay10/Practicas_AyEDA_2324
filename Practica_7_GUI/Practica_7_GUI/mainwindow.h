#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include "abb.h"

#include <string>
#include <queue>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_insertButton_clicked(); // Ranura para el botón de insertar
    void on_deleteButton_clicked(); // Ranura para el botón de borrar

    void printTree(QString valueToInsert); // Método para imprimir el árbol
    //void drawTree(QGraphicsScene* scene, QGraphicsView* view);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView* view;

    ABB<int> *tree = new ABB<int>();
};

#endif // MAINWINDOW_H

