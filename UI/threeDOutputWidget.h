#ifndef THREEDOUTPUTWIDGET_H
#define THREEDOUTPUTWIDGET_H

#include <QGraphicsView>
#include <QPushButton>
#include <QSlider>
#include "../model.h"

class threeDOutputWidget : public QGraphicsView
{
public:
    explicit threeDOutputWidget(QWidget *parent = 0);
    threeDOutputWidget(QGraphicsScene *scene, QWidget *parent = 0);
    QPushButton *rotateX,*rotateY,*rotateZ;
    QSlider *horizontalSlider;

public slots:
    void drawOutput2D();
    void drawLine();
    void reset();
    void setp1(float x, float y);
    void setp2(float x, float y);

private:
    short int count;
    QImage *img;
    QGraphicsScene *scene;
    QPointF p1, p2;

    QRgb color;
};

#endif
