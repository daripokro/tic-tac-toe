#include "MainWindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName( "" );
    MainWindow w;
    w.show();
    return a.exec();
}
