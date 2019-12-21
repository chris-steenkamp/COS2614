#include <QDebug>
#include "bookinglist.h"
#include "sharing.h"
#include "single.h"

const int BookingList::NO_OF_ROOMS = 2;

BookingList::BookingList(): QList<Booking*>() {}

Booking* BookingList::addBooking(Person c, QDate a, QDate d, Person *g1, Person *g2) {
    Booking *booking = 0;

    if (g1 == 0) {
        qDebug() << "At least one guest needs to be checked in.";
        return 0;
    }
    else if (!vacancy(a, d)) {
        qDebug() << "No more room at the inn!";
        return 0;
    }

    if (g2 != 0) {
        booking = new Sharing(c, a, d, *g1, *g2);
    }
    else {
        booking = new Single(c, a, d, *g1);
    }

    append(booking);

    return booking;
}

void BookingList::deleteAll() {
    qDeleteAll(*this);
    clear();
}

BookingList::~BookingList() {
   deleteAll();
}

int BookingList::roomsAvailable(QDate d) const {
    int roomsAvailable = BookingList::NO_OF_ROOMS;

    for (int i = 0; i < count(); ++i) {
        if (at(i)->booked(d))
            --roomsAvailable;
    }

    return roomsAvailable;
}

bool BookingList::vacancy(QDate a, QDate d) const {
    if (!a.isValid() || !d.isValid() || a >= d) {
            return false;
    }

    QDate checkDate = a;

    while (checkDate < d) {
        if (roomsAvailable(checkDate) < 1)
            return false;

        checkDate = checkDate.addDays(1);
    }

    return true;
}
