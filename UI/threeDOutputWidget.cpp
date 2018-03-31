#include <QDebug>
#include <QImage>
#include <cmath>
#include <QGraphicsTextItem>

#include "threeDOutputWidget.h"

threeDOutputWidget::threeDOutputWidget(QWidget *parent) : QGraphicsView(parent), count(0), img(500, 500, QImage::Format_ARGB32)
{
	setFixedSize(500, 500);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	scene = new QGraphicsScene(this);
	setScene(scene);
	setSceneRect(0, 0, this->width(), this->height());

	color = qRgb(0, 0, 0);
}

void threeDOutputWidget::setp1(float x, float y){
	p1 = QPoint(x,y);
}

void threeDOutputWidget::setp2(float x, float y){
	p2 = QPoint(x,y);
}

void threeDOutputWidget::drawOutput2D()
{
	drawLine();
	scene->addPixmap(QPixmap::fromImage(img));
}

void threeDOutputWidget::drawLine()
{
	//I assume we have a coordinate system with the origin in the upper left corner
	//with the positive axes down and to the right, this is set up in the ctor

	//first point
	QPoint f = p1.toPoint();
	//last point
	QPoint l = p2.toPoint();

	//vertical line
	if(f.x() == l.x())
	{
		qDebug() << "vertical line";

		if(f.y() > l.y())
		{
			qSwap(f, l);
		}

		for(int y=f.y(); y<=l.y(); y++)
		{

			qDebug() << "x:" << f.x() << "y:" << y;
			img.setPixel(f.x(), y, color);
		}

		return;
	}

	//slope
	qreal m = (p2.y() - p1.y())/(p2.x() - p1.x());
	qDebug() << "Slope:" << m;

	//in order to get better effects
	//I should render the line iterating through the longer side
	//the if condition translates into: the rise is higher than the run
	if(m > 1.0 || m < -1.0)
	{
		qDebug() << "the rise is higher than the run";

		m = 1/m;

		//draw the line from the top to bottom
		if(f.y() > l.y())
		{
			qSwap(f, l);
		}

		for(int y=f.y(); y<=l.y(); y++)
		{
			int x = round(m*(y-f.y()) + f.x());
			qDebug() << "x:" << x << "y:" << y;
			img.setPixel(x, y, color);
		}
	}
	else{
		//if the line was drawn right to left, make it so I draw left to right
		if(f.x() > l.x())
		{
			qSwap(f, l);
		}

		for(int x=f.x(); x<=l.x(); x++)
		{
			int y = round(m*(x-f.x()) + f.y());

			qDebug() << "x:" << x << "y:" << y;
			img.setPixel(x, y, color);
		}
	}
}

void threeDOutputWidget::reset()
{
	count = 0;
	scene->clear();
	p1 = p2 = QPoint(0, 0);
}