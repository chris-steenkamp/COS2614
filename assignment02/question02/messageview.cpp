#include <QFormLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QTimer>
#include "messagemodel.h"
#include "messageview.h"
#include "messagelist.h"
#include "sequentialmessagemodel.h"

MessageView::MessageView(MessageModel* const model, QDialog *parent): QDialog(parent),
    m_Model(model),
    m_Timer(new QTimer(this)),
    m_DelaySpinBox(new QSpinBox),
    m_MessageTextEdit(new QTextEdit),
    m_TimerControl(new QPushButton("&Start"))
{
    QFormLayout *layout = new QFormLayout;

    m_DelaySpinBox->setMinimum(5000);
    m_DelaySpinBox->setMaximum(20000);
    m_MessageTextEdit->setReadOnly(true);

    layout->addRow(tr("Delay Timeout (ms)"), m_DelaySpinBox);
    layout->addRow(tr("Message"), m_MessageTextEdit);
    layout->addRow("Message Control", m_TimerControl);
    setLayout(layout);

    connect(m_TimerControl, SIGNAL(clicked()), this, SLOT(controlTimer()));
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(displayMessage()));
}

void MessageView::displayMessage() {
    m_MessageTextEdit->setText(m_Model->getNextMessage());
}

void MessageView::controlTimer() {
    if (m_TimerControl->text() == "&Start") {
        m_Timer->setInterval(m_DelaySpinBox->value());
        displayMessage();
        m_TimerControl->setText("&Stop");
        m_DelaySpinBox->setEnabled(false);
        m_Timer->start();
    }
    else {
        m_TimerControl->setText("&Start");
        m_DelaySpinBox->setEnabled(true);
        m_Timer->stop();
    }
}

MessageView::~MessageView() {
//    delete m_Model;
    m_Model = 0;
}
