#include "orderlist.h"
#include "orderwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OrderList orderList;

    OrderWindow w(&orderList);
    w.show();

    return a.exec();
}
