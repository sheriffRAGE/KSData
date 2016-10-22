#include "mainwindow.h"
#include <QApplication>

//* KSData v0.1

//* A simple tool for Kerbal Space Program

//* Created by: sheriffRAGE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
