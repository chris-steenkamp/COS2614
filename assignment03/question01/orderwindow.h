#ifndef ORDERWINDOW_H
#define ORDERWINDOW_H

#include <QMainWindow>
class Order;
class OrderModel;
class QAction;
class QString;
class QWidget;

namespace Ui {
class OrderWindow;
}

class OrderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrderWindow(OrderModel* orders, QWidget *parent = 0);
    ~OrderWindow();

protected slots:
    void actionEvent(QAction *action);
    void handleOrderCreated(Order *order);

private:
    OrderModel *m_Orders;
    QAction *m_CreateOrder;
    QAction *m_ViewOrderList;

    QWidget *m_CreateOrderForm;
    QWidget *m_ViewOrderListForm;

    QAction* createAction(QString name, QString text);
    void createNewOrderForm();
    void createViewOrderListForm();
};

#endif // ORDERWINDOW_H
