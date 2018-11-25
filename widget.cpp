#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()),this,SLOT(changeColor()));
    timer.start(20);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);
    int width = this->width();
    int height = this->height();

    r += r_speed;
    g += g_speed;
    b += b_speed;

    if (r > 255){
        r_speed = -1;
        r = 255;
    }
    if (r < 0){
        r_speed = 1;
        r = 0;
    }
    if (g > 255){
        g_speed = -2;
        g = 255;
    }
    if (g < 0){
        g_speed = 2;
        g = 0;
    }
    if (b > 255){
        b_speed = -3;
        b = 255;
    }
    if (b < 0){
        b_speed = 3;
        b = 0;
    }




    painter.setBrush(QColor::fromRgb(r%256,g%256,b%256));
    painter.drawRect(0,0,width,height);
}

void Widget::changeColor()
{
    this->repaint();
}
