#ifndef MESSAGELIST_H
#define MESSAGELIST_H

#include <QList>
#include "messagestore.h"

class MessageList: public QList<Message*>, public MessageStore
{
public:
    MessageList();
    ~MessageList();
    const Message& getMessage(int index) const;
    int count() const;
    void addMessage(QString text, Message::MessageType type);
private:
    MessageList(MessageList&);
    MessageList& operator=(MessageList&);
};

#endif // MESSAGELIST_H
