#ifndef WIDGET1_H
#define WIDGET1_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_zeroButton_clicked();

    void on_oneButton_clicked();

    void on_Enter_clicked();

    void on_RefreshButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET1_H
