#include "textbookmap.h"
#include "textbook.h"

#include <QString>
#include <QDebug>

TextbookMap::~TextbookMap() {
    qDebug() << "Destroying TextbookMap ..." << endl;
    qDeleteAll(*this);
    clear();
}

void TextbookMap::add(Textbook* text) {
    insert(text->getIsbn(), text);
}

QString TextbookMap::toString() const {
    QString retval;
    QTextStream os(&retval);
    ConstIterator itr = constBegin();
    for ( ; itr != constEnd(); ++itr)
        os << '[' << itr.key() << ']' << ": "
        << itr.value()->toString() << endl;
    return retval;
}

bool TextbookMap::foundTextbook(QString isbn) const
{
    return find(isbn) != end();
}

void TextbookMap::deleteTextbook(QString isbn)
{
    Textbook *item = take(isbn);
    delete item;
}

QStringList TextbookMap::textBookInfo(QString author)
{
    QStringList list;

    for (ConstIterator itr = begin(); itr != constEnd(); ++itr)
    {
        if (itr.value()->getAuthor() == author)
        {
            list.append(itr.value()->toString());
        }
    }

    return list;
}
