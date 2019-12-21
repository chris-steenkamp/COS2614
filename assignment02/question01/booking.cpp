#include "booking.h"

const double Booking::SINGLE_PPPN = 250.00;
const double Booking::SHARING_PPPN = 200.00;

Booking::Booking(Person c, QDate a, QDate d): m_Contact(c), m_ArrivalDate(a), m_DepartureDate(d) {}

Booking::~Booking() {}

QString Booking::toString() const {
    return QString("Details of booking for the period %2 to %3\nBooked By: %1")
            .arg(m_Contact.toString())
            .arg(m_ArrivalDate.toString("dd/MM/yyyy"))
            .arg(m_DepartureDate.toString("dd/MM/yyyy"));
}

bool Booking::booked(QDate d) const {
    return d >= m_ArrivalDate && d < m_DepartureDate;
}
