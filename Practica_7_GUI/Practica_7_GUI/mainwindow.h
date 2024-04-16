#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>

#include <string>

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    AB<int> *tree; 
};

#endif // MAINWINDOW_H

