#include "mainwindow.h"
#include "eightqueens.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    EightQueens eightQueens;
    eightQueens.run();
    w.setSolutions(eightQueens.getSolutions());
    w.show();
    return a.exec();
}
