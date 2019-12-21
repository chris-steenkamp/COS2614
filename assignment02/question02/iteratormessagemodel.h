#ifndef ITERATORMESSAGEMODEL_H
#define ITERATORMESSAGEMODEL_H

#include "messagelist.h"
#include "messagemodel.h"

class IteratorMessageModel : public MessageModel
{
public:
    IteratorMessageModel(MessageList* messages);
    QString getNextMessage();
private:
    MessageList::const_iterator m_Iter;
};

#endif // ITERATORMESSAGEMODEL_H
