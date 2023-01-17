#include "unitywidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UnityWidget w;
    w.show();
    return a.exec();
}
