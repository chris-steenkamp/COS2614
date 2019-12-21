#include "createorder.h"
#include "order.h"

#include <QDateEdit>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QVBoxLayout>

CreateOrder::CreateOrder(QWidget *parent) :
    QWidget(parent),
    m_NameLineEdit(new QLineEdit(this)),
    m_DateAddedDateEdit(new QDateEdit(this)),
    m_QuantitySpinBox(new QSpinBox(this)),
    m_UnitPriceDoubleSpinBox(new QDoubleSpinBox(this)),
    m_TotalPriceLineEdit(new QLineEdit(this)),
    m_BtnOk(new QPushButton(tr("&Ok"),this)),
    m_BtnCancel(new QPushButton(tr("&Cancel"), this))
{
    m_DateAddedDateEdit->setDate(QDate::currentDate());
    m_QuantitySpinBox->setValue(1);
    m_UnitPriceDoubleSpinBox->setValue(1);
    m_TotalPriceLineEdit->setReadOnly(true);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(tr("&Name"), m_NameLineEdit);
    formLayout->addRow(tr("&Date Added"), m_DateAddedDateEdit);
    formLayout->addRow("&Quantity", m_QuantitySpinBox);
    formLayout->addRow("&Unit Price", m_UnitPriceDoubleSpinBox);
    formLayout->addRow("&Total Price", m_TotalPriceLineEdit);
    mainLayout->addLayout(formLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(m_BtnOk);
    buttonLayout->addWidget(m_BtnCancel);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

    connect(m_BtnOk, SIGNAL(clicked(bool)), this, SLOT(handleOk()));
    connect(m_BtnCancel, SIGNAL(clicked(bool)), this, SLOT(handleCancel()));
    connect(m_QuantitySpinBox, SIGNAL(valueChanged(int)), this, SLOT(handlePriceChange()));
    connect(m_UnitPriceDoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(handlePriceChange()));
}

CreateOrder::~CreateOrder()
{
}

void CreateOrder::handleOk()
{
    Order *order = new Order(m_NameLineEdit->text(), m_DateAddedDateEdit->date(), m_QuantitySpinBox->value(), m_UnitPriceDoubleSpinBox->value());
    emit orderCreated(order);
    setVisible(false);
}

void CreateOrder::handleCancel()
{
    hide();
}

void CreateOrder::handlePriceChange()
{
    m_TotalPriceLineEdit->setText(QString::number(m_UnitPriceDoubleSpinBox->value()*m_QuantitySpinBox->value(), 'f', 2));
}
