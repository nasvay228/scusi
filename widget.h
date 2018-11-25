#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
int r = 0;
int g = 0;
int b = 0;
int r_speed = 1;
int g_speed = 2;
int b_speed = 3;
private:
    Ui::Widget *ui;
    QTimer timer;
protected:
    void paintEvent(QPaintEvent * e);
protected slots:
    void changeColor();
};

#endif // WIDGET_H
