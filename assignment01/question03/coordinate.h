#ifndef COORDINATE_H
#define COORDINATE_H
#include <QChar>
#include <QString>

class Coordinate
{
private:
    int m_Degrees;
    int m_Minutes;
    int m_Seconds;
    QChar m_Direction;

public:
    Coordinate(int degrees, int minutes, int seconds, QChar direction);
    QString toString() const;
    double toDecimal() const;
    int degrees() const;
    int minutes() const;
    int seconds() const;
    QChar direction() const;
};

#endif // COORDINATE_H
