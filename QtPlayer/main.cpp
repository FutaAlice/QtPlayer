#include "QtPlayer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtPlayer w;
    w.show();
    return a.exec();
}
