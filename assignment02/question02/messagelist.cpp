#include <QDebug>
#include <QString>
#include "message.h"
#include "messagelist.h"

MessageList::MessageList(): QList<Message*>(), MessageStore() {}

MessageList::MessageList(MessageList&) : QList<Message*>(), MessageStore() {}

MessageList& MessageList::operator=(MessageList&) {
    return *this;
}

MessageList::~MessageList() {
    qDebug() << "Clearing up Messages";
    qDeleteAll(*this);
    clear();
}

const Message& MessageList::getMessage(int index) const {
    return *at(index);
}

int MessageList::count() const {
    return QList<Message*>::count();
}

void MessageList::addMessage(QString text, Message::MessageType type) {
    append(new Message(text, type));
}
