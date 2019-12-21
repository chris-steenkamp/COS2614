#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include "message.h"
#include "messagelist.h"
#include "messageview.h"
#include "randommessagemodel.h"
#include "sequentialmessagemodel.h"

void loadMessages(MessageList& list, const char* filename, Message::MessageType type) {
    QFile file(filename);
    file.open(QFile::ReadOnly);
    QTextStream cin(&file);
    QStringList messages = cin.readAll().split("\n%");

    foreach (const QString message, messages) {
        list.addMessage(message.trimmed(), type);
    }

    file.close();
}

void cleanup() {
    qDebug() << "Fokof";
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    /*
     * MessageList is a composition of Message* so it manages the creation
     * and deletion of the underlying messages automatically.
     */
    MessageList list;
    /*
     * A list is an aggeregate on a model and so is not managed by the model
     * itself. This allows us to pass a MessageList created using any method
     * (or from any source) into the model, without the model having
     * to worry where the list values are coming from.
     */
    RandomMessageModel model(&list);

    /*
     * A view has an aggregate relationship with a model and so the model
     * is created and destroyed outside of the view itself. This allows
     * different models to be assigned to the view dynamically.
     */
    //Uncomment below to test a different model with the same view
    //SequentialMessageModel model(&list);
    MessageView form(&model);

    /*
     * Populate the list with text messages loaded as resources.
     * Each file contains a different type of message so we specify
     * the Message::MessageType when loading.
     */
    loadMessages(list, ":/fortunes.txt", Message::Fortune);
    loadMessages(list, ":/riddles.txt", Message::Riddle);

    form.show();

    return app.exec();
}
