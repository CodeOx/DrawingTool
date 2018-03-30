#ifndef MYQGRAPHICSVIEW_H
#define MYQGRAPHICSVIEW_H

#include <QGraphicsView>
#include "../TwoDModelGenerator.h"

class MyQGraphicsView : public QGraphicsView
{
public:
    explicit MyQGraphicsView(QWidget *parent = 0);
    MyQGraphicsView(QGraphicsScene *scene, QWidget *parent = 0);

public slots:
    //void mouseReleaseEvent(QMouseEvent *event);
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

#endif // MYQGRAPHICSVIEW_H
