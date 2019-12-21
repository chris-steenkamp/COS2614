#include <QTextStream>
#include "gpscoord.h"

QTextStream cout(stdout);
QTextStream cin(stdin);

void createNew(GPSCoord g) {

}

int main(int argc, char* argv[]) {
    GPSCoord gps;

    gps.setCoordinate(25,36, 59, 'N');
    gps.setCoordinate(37, 28,44, 'W');

    GPSCoord gps2;

    gps2 = gps;

    gps.setCoordinate(44,28,45,'S');

//    gps2.setCoordinate(37, 28,44, 'W');

//    GPSCoord gps3;
//    gps3 = gps2;

//    gps3.setCoordinate(160, 27, 35, 'S');

    cout << "GPS = " << gps.toString() << endl << flush;
    cout << "GPS2 = " << gps2.toString() << endl << flush;
//    cout << "GPS3 = " << gps3.toString() << endl << flush;

    return 0;
}
