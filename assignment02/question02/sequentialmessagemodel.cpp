#include <QDebug>
#include <QString>
#include "messagestore.h"
#include "sequentialmessagemodel.h"

SequentialMessageModel::SequentialMessageModel(MessageStore* messages): MessageModel(messages), m_CurrentMessage(0) {}

QString SequentialMessageModel::getNextMessage() {
    if (m_CurrentMessage == getMessageStore().count())
        m_CurrentMessage = 0;

    const Message& message = getMessageStore().getMessage(m_CurrentMessage);

    return QString("#%1\n%2")
            .arg(++m_CurrentMessage)
            .arg(message.getText());
}

SequentialMessageModel::~SequentialMessageModel() {
    qDebug() << "Clearing up SequentialMessageModel";
}
