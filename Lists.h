#include "geometry.h"

class PointList{
	Point* points;
	int size;

public:
	Point* getPoints();

	int getSize();

	void setPoints(Point* points);

	void setSize(int size);
	
	void remove(Line l);
};

class LineList{
	Line* lines;
	int size;

public:
	Line* getlines();

	int getSize();

	void setlines(Line* lines);

	void setSize(int size);
};

class planeList{
	Plane* planes;
	int size;

public:
	Plane* getplanes();

	int getSize();

	void setplanes(Plane* planes);

	void setSize(int size);
};

class planeWithLinesList{
	PlaneWithLines* planeWithLines;
	int size;

public:
	PlaneWithLines* getPlaneWithLines();

	int getSize();

	void setPlaneWithLines(PlaneWithLines* p);

	void setSize(int size);
};


#ifndef PLANEWITHLINES_H
#define PLANEWITHLINES_H

/*! \class Plane
A class to represent a plane and the lines lying on it
*/
class PlaneWithLines{
	
	Plane plane;
	std::vector<Line> lines;
	int numLines;

public:
	//! Accessor function to get plane
	Plane getPlane();
	//! Accessor function to get array of lines
	Line* getArrayLines();
	//! Accessor function to get number of lines
	int getNumLines();
	LineList getLines();
  
  	void setPlane(Plane p);
  	void addLine(Line l);

};

#endif
