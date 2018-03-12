#include "geometry.h"

class PointList{
	Point* points;
	int size;

public:
	void getPoints();

	void getSize();

	void setPoints(Point* points);

	void setSize(int size);
};

class LineList{
	line* lines;
	int size;

public:
	void getlines();

	void getSize();

	void setlines(line* lines);

	void setSize(int size);
};

class planeList{
	plane* planes;
	int size;

public:
	void getplanes();

	void getSize();

	void setplanes(plane* planes);

	void setSize(int size);
};