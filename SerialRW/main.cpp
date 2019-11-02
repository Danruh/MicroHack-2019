#include "mainwindow.h"
#include "unlockbutton.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //UnlockButton b;
    //b.show();

    return a.exec();
}
