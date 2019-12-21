#include "textbook.h"
#include <QDebug>
#include <QString>

Textbook::Textbook(QString title, QString author, QString isbn, uint year)
    : m_Title(title), m_Author(author), m_Isbn(isbn), m_YearPub(year)
{

}

Textbook::~Textbook()
{
    qDebug() << "Removing " << m_Isbn;
}

QString Textbook::getAuthor() const
{
    return m_Author;
}

QString Textbook::getTitle() const
{
    return m_Title;
}

QString Textbook::getIsbn() const
{
    return m_Isbn;
}

uint Textbook::getYearPub() const
{
    return m_YearPub;
}

QString Textbook::toString() const
{
    return QString("%1, %2, published %3, ISBN: %4")
            .arg(getTitle())
            .arg(getAuthor())
            .arg(getYearPub())
            .arg(getIsbn());
}

void Textbook::setTitle(const QString& newTitle)
{
    m_Title = newTitle;
}

void Textbook::setIsbn(const QString &newIsbn)
{
    m_Isbn = newIsbn;
}

void Textbook::setYearPub(uint newYear)
{
    m_YearPub = newYear;
}

void Textbook::setAuthor(const QString& newAuthor)
{
    m_Author = newAuthor;
}
