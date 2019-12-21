#ifndef INPUTFORM_H
#define INPUTFORM_H

#include <QDialog>

class MessageModel;
class QSpinBox;
class QTimer;
class QTextEdit;

class MessageView : public QDialog
{
    Q_OBJECT
public:
    explicit MessageView(MessageModel* const model, QDialog *parent = 0);
    ~MessageView();
signals:

public slots:
    void displayMessage();
    void controlTimer();
private:
    MessageModel* m_Model;
    QTimer *m_Timer;
    QSpinBox *m_DelaySpinBox;
    QTextEdit *m_MessageTextEdit;
    QPushButton *m_TimerControl;
};

#endif // INPUTFORM_H
