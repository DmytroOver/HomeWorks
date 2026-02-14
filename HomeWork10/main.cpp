#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Hello QT");

    QWidget *centralWidget = new QWidget(&w);

    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    centralWidget->setLayout(vBoxLayout);

    QLabel* label = new QLabel("Hello World!", centralWidget);
    label->setAlignment(Qt::AlignCenter);

    vBoxLayout->addWidget(label);

    w.setCentralWidget(centralWidget);

    w.show();
    return a.exec();
}
