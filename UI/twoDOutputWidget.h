#ifndef TWODOUTPUTWIDGET_H
#define TWODOUTPUTWIDGET_H

#include <QGraphicsView>
#include "../model.h"

class twoDOutputWidget : public QGraphicsView
{
public:
    explicit twoDOutputWidget(QWidget *parent = 0);
    twoDOutputWidget(QGraphicsScene *scene, QWidget *parent = 0);

public slots:
    void drawOutput2D();
    void drawLine();
    void reset();
    void setp1(float x, float y);
    void setp2(float x, float y);

private:
    short int count;
    QImage img;
    QGraphicsScene *scene;
    QPointF p1, p2;

    QRgb color;
};

#endif
