#ifndef ORDERLIST_H
#define ORDERLIST_H

#include "ordermodel.h"
#include <QList>
class Order;
class QString;
class QDate;

class OrderList : public QList<Order*>, public OrderModel
{
public:
    OrderList();
    ~OrderList();

    void addOrder(Order* order);
    const Order& getOrder(int index) const;
    int count() const;
private:
    OrderList(const OrderList&);
    OrderList& operator=(const OrderList&);
};

#endif // ORDERLIST_H
