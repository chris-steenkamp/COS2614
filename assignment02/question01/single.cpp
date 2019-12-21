#include <QDebug>
#include "single.h"

Single::Single(Person c, QDate a, QDate d, Person g): Booking(c, a, d), m_Guest(g) { }

Single::~Single() {
    qDebug() << "Removing Single Booking";
}

double Single::rate() const{
    return Booking::SINGLE_PPPN;
}

QString Single::toString() const {
    return QString("%1\nSingle guest at a rate of ZAR%2 per room, per night:\nGuest Details: %3\n")
            .arg(Booking::toString())
            .arg(QString::number(rate(), 'f', 2))
            .arg(m_Guest.toString());
}
