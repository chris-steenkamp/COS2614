#include <QDebug>
#include "gpscoord.h"

QTextStream cerr(stderr);

Coordinate* copyCoordinate(const Coordinate& other) {
    qDebug(QString("Copying Coordinate " + other.toString()).toStdString().c_str());
    return new Coordinate(other.degrees()
                          , other.minutes()
                          , other.seconds()
                          , other.direction());
}

GPSCoord::GPSCoord()
 : m_Latitude(new Coordinate(0,0,0, 'N')), m_Longitude(new Coordinate(0,0,0, 'E')) {
    qDebug("Constructing GPSCoord object.");
}

GPSCoord::~GPSCoord() {
    qDebug("Destroying GPSCoord object.");
    delete m_Latitude;
    m_Latitude = 0;

    delete m_Longitude;
    m_Longitude = 0;
}

GPSCoord::GPSCoord(const GPSCoord& g)
    : m_Latitude(copyCoordinate(*g.m_Latitude)),
      m_Longitude(copyCoordinate(*g.m_Longitude))
{
    qDebug("Copy Constructing new GPSCoord");
}

GPSCoord& GPSCoord::operator=(const GPSCoord& g) {
    qDebug("Assigning new values to GPSCoord object.");

    *m_Latitude = *g.m_Latitude;
//    delete m_Latitude;
//    m_Latitude = copyCoordinate(*g.m_Latitude);

    *m_Longitude = *g.m_Longitude;
//    delete m_Longitude;
//    m_Longitude = copyCoordinate(*g.m_Longitude);

    return *this;
}

void GPSCoord::setCoordinate(int degrees, int minutes, int seconds, QChar direction) {
	if (direction == 'N' || direction == 'S') {
		delete m_Latitude;
		m_Latitude = new Coordinate(degrees, minutes, seconds, direction);
	}
	else {
		delete m_Longitude;
		m_Longitude = new Coordinate(degrees, minutes, seconds, direction);
	}
}

QString GPSCoord::toString(bool decimal) const {
	if (decimal) {
		return QString("%1 %2").arg(m_Latitude->toDecimal()).arg(m_Longitude->toDecimal());
	}
	else {
		return m_Latitude->toString() + m_Longitude->toString();
	}
}
