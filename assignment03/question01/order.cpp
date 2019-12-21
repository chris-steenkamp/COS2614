#include "order.h"

Order::Order(QString name, QDate dateAdded, int quantity, double unitPrice)
    : m_Name(name), m_DateAdded(dateAdded), m_Quantity(quantity), m_UnitPrice(unitPrice)
{

}

double Order::getTotalPrice() const
{
    return m_UnitPrice * m_Quantity;
}

QString Order::getName() const
{
    return m_Name;
}

QDate Order::getDateAdded() const
{
    return m_DateAdded;
}

int Order::getQuantity() const
{
    return m_Quantity;
}

double Order::getUnitPrice() const
{
    return m_UnitPrice;
}

QString Order::toString() const
{
    return QString("%1 %2 (%3) @ R %4 Total R: %5")
            .arg(getName())
            .arg(getDateAdded().toString("yyyy/MM/dd"))
            .arg(getQuantity())
            .arg(QString::number(getUnitPrice(), 'f', 0))
            .arg(QString::number(getTotalPrice(), 'f', 0));
}
