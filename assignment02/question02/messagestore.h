#ifndef MESSAGESTORE_H
#define MESSAGESTORE_H

#include "message.h"

class QString;

class MessageStore
{
public:
    virtual ~MessageStore() {}
    virtual const Message& getMessage(int index) const = 0;
    virtual int count() const = 0;
    virtual void addMessage(QString text, Message::MessageType type) = 0;
};

#endif // MESSAGESTORE_H
