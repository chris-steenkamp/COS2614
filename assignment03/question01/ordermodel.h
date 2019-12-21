#ifndef ORDERMODEL_H
#define ORDERMODEL_H

class Order;

class OrderModel
{
public:
    OrderModel();
    virtual ~OrderModel();
    virtual void addOrder(Order* order) = 0;
    virtual const Order& getOrder(int index) const = 0;
    virtual int count() const = 0;
private:
    OrderModel(const OrderModel&);
    OrderModel& operator=(const OrderModel&);
};

#endif // ORDERMODEL_H
