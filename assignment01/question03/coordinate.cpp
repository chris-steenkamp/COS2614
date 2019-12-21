#include "coordinate.h"

Coordinate::Coordinate(int degrees, int minutes, int seconds, QChar direction)
    : m_Degrees(degrees), m_Minutes(minutes), m_Seconds(seconds), m_Direction(direction.toUpper())
{

}

QString Coordinate::toString() const {
    return QString("%1%2 %3' %4\" %5")
            .arg(m_Degrees)
            .arg(QChar(248))
            .arg(m_Minutes)
            .arg(m_Seconds)
            .arg(m_Direction);
}

double Coordinate::toDecimal() const {
    return (m_Degrees + (m_Minutes / 60) + (m_Seconds / 3600))
            * (m_Direction == 'N' || m_Direction == 'E' ? 1 : -1);
}

int Coordinate::degrees() const {
    return m_Degrees;
}

int Coordinate::minutes() const {
    return m_Minutes;
}

int Coordinate::seconds() const {
    return m_Seconds;
}

QChar Coordinate::direction() const {
    return m_Direction;
}
