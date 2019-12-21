#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H

class QString;
class MessageStore;

class MessageModel
{
public:
    MessageModel(MessageStore* const messages);
    virtual ~MessageModel();
    virtual QString getNextMessage() = 0;
protected:
    const MessageStore& getMessageStore() const;
private:
    MessageModel(const MessageModel&);
    MessageModel& operator=(const MessageModel&);
    MessageStore* m_Messages;
};

#endif // MESSAGEMODEL_H
