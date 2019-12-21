#ifndef BOOKING_H
#define BOOKING_H
#include <QDate>
#include <QString>
#include "person.h"

class Booking
{
public:
    static const double SINGLE_PPPN;
    static const double SHARING_PPPN;

    Booking(Person c, QDate a,QDate d);
    virtual ~Booking();
    virtual QString toString() const;
    bool booked(QDate d) const;
    virtual double rate() const = 0;
private:
    Person m_Contact;
    QDate m_ArrivalDate;
    QDate m_DepartureDate;
};

#endif // BOOKING_H
