#include <QDebug>
#include "sharing.h"

Sharing::Sharing(Person c, QDate a, QDate d, Person g1, Person g2): Booking(c, a, d), m_Guest1(g1), m_Guest2(g2) {}

Sharing::~Sharing() {
    qDebug() << "Removing Sharing Booking";
}

double Sharing::rate() const {
    return 2 * Booking::SHARING_PPPN;
}

QString Sharing::toString() const {
    return QString("%1\nTwo guests sharing at a rate of ZAR%2 per room, per night:\nGuest 1 Details: %3\nGuest 2 Details: %4\n")
            .arg(Booking::toString())
            .arg(QString::number(rate(), 'f', 2))
            .arg(m_Guest1.toString())
            .arg(m_Guest2.toString());
}
