#ifndef TEXTBOOKMAP_H
#define TEXTBOOKMAP_H

#include "textbook.h"
#include <QMap>
class QString;

class TextbookMap : public QMap<QString, Textbook*> {
  public:
    ~TextbookMap();
    /** Adds the TextBook to the map, keyed on the ISBN */
    void add(Textbook* text);
    QString toString() const;
    bool foundTextbook(QString isbn) const;
    void deleteTextbook(QString isbn);
    QStringList textBookInfo(QString author);
};

#endif // TEXTBOOKMAP_H
