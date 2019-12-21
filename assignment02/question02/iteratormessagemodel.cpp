#include "iteratormessagemodel.h"
#include "messagelist.h"
#include "message.h"

IteratorMessageModel::IteratorMessageModel(MessageList* messages) : MessageModel(messages), m_Iter(messages->constBegin()) {}

QString IteratorMessageModel::getNextMessage(){
    m_Iter++;
    return (*m_Iter)->getText();
}
