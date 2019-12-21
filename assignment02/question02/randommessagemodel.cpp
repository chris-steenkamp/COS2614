#include <QDebug>
#include <QString>
#include <QTime>
#include "messagestore.h"
#include "randommessagemodel.h"

RandomMessageModel::RandomMessageModel(MessageStore* messages) : MessageModel(messages) {
    qsrand(QTime::currentTime().msec());
}

QString RandomMessageModel::getNextMessage() {
    int randomIndex = (qrand() % getMessageStore().count());
    const Message& message = getMessageStore().getMessage(randomIndex);

    return QString("#%1\n%2")
            .arg(randomIndex+1)
            .arg(message.getText());
}

RandomMessageModel::~RandomMessageModel() {
    qDebug() << "Clearing up RandomMessageModel";
}
