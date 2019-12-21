#ifndef RANDOMMESSAGEMODEL_H
#define RANDOMMESSAGEMODEL_H

#include "messagemodel.h"

class RandomMessageModel : public MessageModel
{
public:
    RandomMessageModel(MessageStore* messages);
    ~RandomMessageModel();
    QString getNextMessage();
};

#endif // RANDOMMESSAGEMODEL_H
