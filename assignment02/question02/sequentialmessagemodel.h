#ifndef SEQUENTIALMESSAGEMODEL_H
#define SEQUENTIALMESSAGEMODEL_H

#include "messagemodel.h"

class SequentialMessageModel : public MessageModel
{
public:
    SequentialMessageModel(MessageStore* messages);
    ~SequentialMessageModel();
    QString getNextMessage();
private:
    int m_CurrentMessage;
};


#endif // SEQUENTIALMESSAGEMODEL_H
