#include "halconvs.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HalconVs w;
    w.show();
    return a.exec();
}
