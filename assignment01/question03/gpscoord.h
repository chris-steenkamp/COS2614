#ifndef GPSCOORD_H
#define GPSCOORD_H
#include "coordinate.h"

class GPSCoord
{
private:
    Coordinate* m_Latitude;
    Coordinate* m_Longitude;
public:
    GPSCoord();
    ~GPSCoord();
    GPSCoord(const GPSCoord& gr);
    GPSCoord& operator=(const GPSCoord& g);
    void setCoordinate(int degrees, int minutes, int seconds, QChar direction);
    QString toString(bool decimal = false) const;
};

#endif // GPSCOORD_H
