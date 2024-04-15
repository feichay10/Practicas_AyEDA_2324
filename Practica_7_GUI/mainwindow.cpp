#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr)
        : QMainWindow(parent)
    {
        // Configurar la ventana principal
        setWindowTitle(tr("Ejemplo de AVL"));

        // Crear los widgets
        QWidget *centralWidget = new QWidget(this);
        QVBoxLayout *layout = new QVBoxLayout(centralWidget);
        setCentralWidget(centralWidget);

        lineEditInsert = new QLineEdit(this);
        lineEditDelete = new QLineEdit(this);

        QPushButton *pushButtonInsert = new QPushButton(tr("Insertar"), this);
        QPushButton *pushButtonDelete = new QPushButton(tr("Eliminar"), this);

        layout->addWidget(lineEditInsert);
        layout->addWidget(pushButtonInsert);
        layout->addWidget(lineEditDelete);
        layout->addWidget(pushButtonDelete);

        // Conectar los botones a las funciones correspondientes
        connect(pushButtonInsert, &QPushButton::clicked, this, &MainWindow::insertNode);
        connect(pushButtonDelete, &QPushButton::clicked, this, &MainWindow::deleteNode);
    }

private slots:
    void insertNode() {
        // Obtener el valor a insertar desde lineEditInsert
        QString valueToInsert = lineEditInsert->text();
        // Aquí iría tu lógica para insertar el nodo en tu estructura AVL
        // Puedes usar valueToInsert.toStdString() para obtener el valor como std::string
        // y luego convertirlo a int o lo que sea necesario para tu implementación AVL
        // Supongamos que tienes una función insertNodeAVL que toma un valor entero como argumento
        // y la has definido en otro lugar de tu código
        // Por ejemplo:
        // insertNodeAVL(valueToInsert.toInt());
        QMessageBox::information(this, tr("Insertar"), tr("Se insertó el nodo: ") + valueToInsert);
    }

    void deleteNode() {
        // Obtener el valor a eliminar desde lineEditDelete
        QString valueToDelete = lineEditDelete->text();
        // Aquí iría tu lógica para eliminar el nodo de tu estructura AVL
        // Similar a la inserción, supongamos que tienes una función deleteNodeAVL
        // que toma un valor entero como argumento y la has definido en otro lugar de tu código
        // Por ejemplo:
        // deleteNodeAVL(valueToDelete.toInt());
        QMessageBox::information(this, tr("Eliminar"), tr("Se eliminó el nodo: ") + valueToDelete);
    }

private:
    QLineEdit *lineEditInsert;
    QLineEdit *lineEditDelete;
};

#include "main.moc"
