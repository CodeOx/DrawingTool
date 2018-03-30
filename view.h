#include "geometry.h"

#ifndef TWODVIEW_H
#define TWODVIEW_H

class TwoDView{
	//! Private array of points and lines are instantiated 
	Point* points; /*< points represents the vertices */
	int pointSize = 0;
	Line* lines; /*< lines represents the edges */
	int lineSize = 0;

public:
	//! Accessor function to get the array of points
	Point* getPoints();
	//! Accessor function to get the array of lines
	Line* getLines();
	
	void setPoints(Point* p);
	void setLines(Line* l);
	
	int getPointSize();
	int getLineSize();
	
	void setPointSize(int s);
	void setLineSize(int s);
};

#endif