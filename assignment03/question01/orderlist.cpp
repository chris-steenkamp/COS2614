#include "orderlist.h"
#include "order.h"
#include <QDate>
#include <QDebug>
#include <QString>

OrderList::OrderList() : QList<Order*>(), OrderModel() {}

OrderList::~OrderList() {
    qDebug() << "Clearing orders";
    qDeleteAll(*this);
    clear();
}

void OrderList::addOrder(Order* order)
{
    append(order);
}

const Order& OrderList::getOrder(int index) const
{
    return *at(index);
}

OrderList::OrderList(const OrderList &) : QList<Order*>(), OrderModel() {}

OrderList& OrderList::operator=(const OrderList&)
{
    return *this;
}

int OrderList::count() const
{
    return QList<Order*>::count();
}
