#include "vendor.h"

Vendor::Vendor()
{
}

void Vendor::setDetails(QString name, QString email, bool isManufacturer) {
    m_Name = name;
    m_Email = email;
    m_IsManufacturer = isManufacturer;
}

bool Vendor::isManufacturer() const {
    return m_IsManufacturer;
}

QString Vendor::getName() const {
    return m_Name;
}

QString Vendor::toString() const {
    return QString("Vendor Name: %1\nVendor Email: %2\nVendor Is Manufacturer: %3").arg(m_Name).arg(m_Email).arg(m_IsManufacturer ? "Yes" : "No");
}
