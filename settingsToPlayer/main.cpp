#include "widget.h"
#include <QApplication>

#include "QFileInfo"
#include "QLabel"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();


    return a.exec();
}
