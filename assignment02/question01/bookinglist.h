#ifndef BOOKINGLIST_H
#define BOOKINGLIST_H
#include <QList>
#include "booking.h"
class QDate;
class Person;

class BookingList : public QList<Booking*>
{
public:
    static const int NO_OF_ROOMS;
    BookingList();
    ~BookingList();

    int roomsAvailable(QDate d) const;
    bool vacancy(QDate a, QDate d) const;

    Booking* addBooking(Person c, QDate a, QDate d, Person *g1, Person *g2=0);
    void deleteAll();
private:
    BookingList(BookingList &): QList<Booking*>() {}
    BookingList& operator=(const BookingList&) {return *this;}
};

#endif // BOOKINGLIST_H
