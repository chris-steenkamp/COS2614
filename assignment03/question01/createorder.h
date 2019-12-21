#ifndef CREATEORDER_H
#define CREATEORDER_H

#include <QWidget>
class Order;
class QDateEdit;
class QDoubleSpinBox;
class QLineEdit;
class QPushButton;
class QSpinBox;

class CreateOrder : public QWidget
{
    Q_OBJECT

public:
    explicit CreateOrder(QWidget *parent = 0);
    ~CreateOrder();

signals:
    void orderCreated(Order*);

protected slots:
    void handleOk();
    void handleCancel();
    void handlePriceChange();
private:
    QLineEdit *m_NameLineEdit;
    QDateEdit *m_DateAddedDateEdit;
    QSpinBox *m_QuantitySpinBox;
    QDoubleSpinBox *m_UnitPriceDoubleSpinBox;
    QLineEdit *m_TotalPriceLineEdit;
    QPushButton *m_BtnOk;
    QPushButton *m_BtnCancel;
};

#endif // CREATEORDER_H
