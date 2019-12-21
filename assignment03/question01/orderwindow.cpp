#include "createorder.h"
#include "ordermodel.h"
#include "orderwindow.h"
#include "vieworderlist.h"

#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

OrderWindow::OrderWindow(OrderModel* orders, QWidget *parent) :
    QMainWindow(parent), m_Orders(orders), m_CreateOrderForm(0), m_ViewOrderListForm(0)
{
    resize(640, 480);
    QMenu* menu = new QMenu(tr("&Orders"), this);

    m_CreateOrder = createAction("m_CreateOrder", "&Add Order");
    m_ViewOrderList = createAction("m_ViewOrders", "&View All Orders");
    m_ViewOrderList->setEnabled(false);

//    menu->addAction(m_CreateOrder);
//    menu->addAction(m_ViewOrderList);


//    this->menuBar()->addMenu(menu);

    QActionGroup *actionGroup = new QActionGroup(this);
    actionGroup->setExclusive(false);
    actionGroup->addAction(m_CreateOrder);
    actionGroup->addAction(m_ViewOrderList);

    menu->addActions(actionGroup->actions());
    menuBar()->addMenu(menu);

    QToolBar *toolbar = new QToolBar("Tools");
    toolbar->addActions(actionGroup->actions());
    addToolBar(Qt::LeftToolBarArea, toolbar);

    connect(actionGroup, SIGNAL(triggered(QAction*)), this, SLOT(actionEvent(QAction*)));
}

void OrderWindow::actionEvent(QAction *action)
{
    if (action == m_CreateOrder) {
        createNewOrderForm();
        setCentralWidget(m_CreateOrderForm);

    }
    if (action == m_ViewOrderList) {
        createViewOrderListForm();
        setCentralWidget(m_ViewOrderListForm);
    }
}

QAction* OrderWindow::createAction(QString name, QString text)
{
    QAction *action = new QAction(text, this);
    action->setObjectName(name);

    return action;
}

OrderWindow::~OrderWindow()
{
    m_Orders = 0;
}

void OrderWindow::handleOrderCreated(Order *order)
{
    m_Orders->addOrder(order);
    m_ViewOrderList->setEnabled(true);
}

void OrderWindow::createNewOrderForm()
{
    m_CreateOrderForm = new CreateOrder(this);
    connect(m_CreateOrderForm, SIGNAL(orderCreated(Order*)), this, SLOT(handleOrderCreated(Order*)));
}

void OrderWindow::createViewOrderListForm()
{
    m_ViewOrderListForm = new ViewOrderList(m_Orders, this);
}
