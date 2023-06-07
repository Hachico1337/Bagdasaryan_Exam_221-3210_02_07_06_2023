
#include "mainwindow.h"
#include "singletonclient.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle(NULL);


    return a.exec();
}
