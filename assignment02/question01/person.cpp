#include "person.h"

Person::Person(QString n, QString c, QString e): m_Name(n), m_ContactNo(c), m_Email(e) {}

QString Person::toString() const {
    return QString("%1, (c) %2, (e) %3")
            .arg(m_Name)
            .arg(m_ContactNo)
            .arg(m_Email);
}
