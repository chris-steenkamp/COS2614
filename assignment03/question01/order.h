#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QDate>

class Order
{
public:
    Order(QString name, QDate dateAdded, int quantity, double unitPrice);
    double getTotalPrice() const;
    QString getName() const;
    QDate getDateAdded() const;
    int getQuantity() const;
    double getUnitPrice() const;
    QString toString() const;
private:
    QString m_Name;
    QDate m_DateAdded;
    int m_Quantity;
    double m_UnitPrice;

};

#endif // ORDER_H
