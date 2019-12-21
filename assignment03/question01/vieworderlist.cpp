#include "order.h"
#include "ordermodel.h"
#include "vieworderlist.h"

#include <QHBoxLayout>
#include <QTextEdit>

ViewOrderList::ViewOrderList(OrderModel *model, QWidget *parent) :
    QWidget(parent),
    m_ViewOrderTextEdit(new QTextEdit(this)),
    m_Model(model)
{
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_ViewOrderTextEdit);

    setLayout(mainLayout);

    for (int i = 0; i < m_Model->count(); ++i)
        m_ViewOrderTextEdit->append(m_Model->getOrder(i).toString());
}

ViewOrderList::~ViewOrderList()
{
    m_Model = 0;
}
