#include <QTextStream>
#include "bookinglist.h"

static QTextStream cout(stdout);

void displayBookingDetails(Booking *b) {
    if (b)
        cout << b->toString() << endl << flush;
    else
        cout << "Unable to create booking." << endl << flush;
}

int main(int, char *[])
{
    BookingList house;

    Person bookerT("Booker T", "0723456789", "bookert@travel.com");
    Person chris("Chris S", "0821234567", "chris@gmail.com");
    Person carmen("Carmen A", "0822345678", "carmen@hotmail.com");
    Person dave("Dave S", "0721234567", "dave@webmail.co.za");
    Person john("John J", "0839871234", "john@nowhere.com");

    displayBookingDetails(house.addBooking(bookerT, QDate(2018,4,1), QDate(2018,4,3), &chris, &carmen));
    displayBookingDetails(house.addBooking(bookerT, QDate(2018,4,1), QDate(2018,4,3), &dave));
    displayBookingDetails(house.addBooking(bookerT, QDate(2018,4,1), QDate(2018,4,3), &john));
}
