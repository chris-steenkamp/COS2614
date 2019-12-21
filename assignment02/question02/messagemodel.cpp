#include <QDebug>
#include "messagemodel.h"
#include "messagestore.h"

MessageModel::MessageModel(MessageStore* const messages) : m_Messages(messages) {}

MessageModel::~MessageModel() {
    qDebug() << "Clearing up MessageModel";
}

const MessageStore& MessageModel::getMessageStore() const {
    return *m_Messages;
}

MessageModel::MessageModel(const MessageModel& other) : m_Messages(other.m_Messages) {}

MessageModel& MessageModel::operator=(const MessageModel& other) {
    this->m_Messages = other.m_Messages;
    return *this;
}
