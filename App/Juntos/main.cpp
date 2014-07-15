#include "mainwindow.h"
#include <QApplication>
#include <vector>
#include "ticket.h"

using namespace std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();


    return a.exec();
}
