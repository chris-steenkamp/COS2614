#ifndef SHARING_H
#define SHARING_H
#include "booking.h"

class Sharing : public Booking
{
public:
    Sharing(Person c, QDate a, QDate d, Person g1, Person g2);
    ~Sharing();
    double rate() const;
    QString toString() const;
private:
    Person m_Guest1;
    Person m_Guest2;
};

#endif // SHARING_H
