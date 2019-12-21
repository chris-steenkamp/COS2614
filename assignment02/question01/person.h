#ifndef PERSON_H
#define PERSON_H
#include <QString>

class Person
{
public:
    Person(QString n, QString c, QString e);
    QString toString() const;
private:
    QString m_Name;
    QString m_ContactNo;
    QString m_Email;
};

#endif // PERSON_H
