#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    // Ajustar la escena a la vista
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

    // Agregar la vista al diseño de la ventana principal
    //ui->verticalLayout->addWidget(view);

    // Desconectar las señales de clic de los botones para evitar conexiones múltiples
    disconnect(ui->insertButton, &QPushButton::clicked, this, &MainWindow::on_insertButton_clicked);
    disconnect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::on_deleteButton_clicked);

    // Conectar las señales de clic de los botones a las ranuras correspondientes
    connect(ui->insertButton, &QPushButton::clicked, this, &MainWindow::on_insertButton_clicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::on_deleteButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insertButton_clicked()
{
    QString valueToInsert = ui->lineEdit_Insert->text();
    if (!valueToInsert.isEmpty()) {
        int value = valueToInsert.toInt();

        tree->insert(value);
        tree->write(std::cout);

        //printTree(valueToInsert);

        tree->drawTree(scene, view);

        // Limpiamos el campo de texto después de la inserción
        ui->lineEdit_Insert->clear();
    } else {
        qDebug() << "Please enter a value to insert.";
    }
}

void MainWindow::on_deleteButton_clicked()
{
    
}

void MainWindow::printTree(QString valueToInsert) {
    // Creamos el círculo
    QGraphicsEllipseItem *circle = scene->addEllipse(0, 0, 50, 50);
    circle->setBrush(QBrush(Qt::blue)); // Color del círculo

    // Posicionamos el círculo en la escena
    circle->setPos(100, 100); // Posición del círculo en la escena

    // Creamos el texto dentro del círculo
    QGraphicsTextItem *text = scene->addText(valueToInsert);
    text->setDefaultTextColor(Qt::white); // Color del texto
    text->setFont(QFont("Arial", 12)); // Fuente y tamaño del texto

    // Calculamos la posición del texto para que esté centrado en el círculo
    qreal textWidth = text->boundingRect().width();
    qreal textHeight = text->boundingRect().height();
    qreal circleWidth = circle->rect().width();
    qreal circleHeight = circle->rect().height();
    qreal xPos = circle->pos().x() + (circleWidth - textWidth) / 2;
    qreal yPos = circle->pos().y() + (circleHeight - textHeight) / 2;
    text->setPos(xPos + circle->rect().x(), yPos + circle->rect().y()); // Ajuste adicional para tener en cuenta la posición del círculo    
}
