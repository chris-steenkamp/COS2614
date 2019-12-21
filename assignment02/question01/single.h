#ifndef SINGLE_H
#define SINGLE_H
#include "booking.h"

class Single : public Booking
{
public:
    Single(Person c, QDate a, QDate d, Person g);
    ~Single();
    double rate() const;
    QString toString() const;
private:
    Person m_Guest;
};

#endif // SINGLE_H
