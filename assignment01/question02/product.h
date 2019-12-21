#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>
#include "vendor.h"

class Product
{
private:
    QString m_Name;
    double m_Price;
    Vendor m_Supplier;
public:
    Product(QString name, double price);
    void setSupplier(QString name, QString email, bool isManufacturer);
    QString getManufacturerName() const;
    QString toString(bool supplierDetails = false) const;
};

#endif // PRODUCT_H
