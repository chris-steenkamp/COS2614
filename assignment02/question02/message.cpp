#include <QString>
#include "message.h"

Message::Message(QString text, MessageType type): m_Text(text), m_Type(type){}

QString Message::getText() const {
    return m_Text;
}

Message::MessageType Message::getType() const {
    return m_Type;
}

QString Message::toString() const {
    return QString("Type = %1\n%2").arg(getType()).arg(getText());
}

