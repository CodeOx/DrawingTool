#include "geometry.h"

class PointList{
	Point* points;
	int size;

public:
	Point* getPoints();

	int getSize();

	void setPoints(Point* points);

	void setSize(int size);
};

class LineList{
	Line* lines;
	int size;

public:
	Line* getlines();

	int getSize();

	void setlines(line* lines);

	void setSize(int size);
};

class planeList{
	Plane* planes;
	int size;

public:
	Plane* getplanes();

	int getSize();

	void setplanes(plane* planes);

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
