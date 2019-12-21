#include "textbook.h"
#include "textbookmap.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    TextbookMap m;
    m.add(new Textbook("The C++ Programming Language","Stroustrup", "0201700735", 1997));
    m.add(new Textbook("XML in a Nutshell",  "Harold","0596002920", 2002));
    m.add(new Textbook("UML Distilled",  "Fowler", "0321193687", 2004));
    m.add(new Textbook("Design Patterns", "Gamma",  "0201633612",1995));
    qDebug() << m.toString();
    qDebug() << "Checking if textbook with isbn 0201700735 exists: " << m.foundTextbook("0201700735");
    qDebug() << "Removing textbook with isbn 0201700735";
    m.deleteTextbook("0201700735");
    qDebug() << "Does textbook with isbn 0201700735 still exist: " << m.foundTextbook("0201700735");
    qDebug() << "Books with Author 'Gamma': " << m.textBookInfo("Gamma");
    return 0;
}
