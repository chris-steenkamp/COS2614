#include "product.h"

Product::Product(QString name, double price)
 : m_Name(name), m_Price(price) {
}

void Product::setSupplier(QString name, QString email, bool isManufacturer) {
    m_Supplier = Vendor();
    m_Supplier.setDetails(name, email, isManufacturer);
}

QString Product::getManufacturerName() const {
    return m_Supplier.isManufacturer() ? m_Supplier.getName() : "Unknown";
}

QString Product::toString(bool supplierDetails) const {
    QString output = QString("Product Name: %1\nProduct Price: %2").arg(m_Name).arg(m_Price);

    if (supplierDetails) {
        output.append('\n').append(m_Supplier.toString());
    }

    return output;
}
