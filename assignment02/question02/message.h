#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>

class Message
{
public:
    enum MessageType {Fortune, Riddle};

    Message(QString text, MessageType type);
    QString getText() const;
    MessageType getType() const;
    QString toString() const;
private:
    QString m_Text;
    MessageType m_Type;
};

#endif // MESSAGE_H
