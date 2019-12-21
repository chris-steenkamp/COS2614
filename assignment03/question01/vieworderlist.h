#ifndef VIEWORDERLIST_H
#define VIEWORDERLIST_H

#include <QWidget>
class QTextEdit;
class OrderModel;

class ViewOrderList : public QWidget
{
    Q_OBJECT

public:
    explicit ViewOrderList(OrderModel *model, QWidget *parent = 0);
    ~ViewOrderList();

private:
    QTextEdit *m_ViewOrderTextEdit;
    OrderModel *m_Model;
};

#endif // VIEWORDERLIST_H
