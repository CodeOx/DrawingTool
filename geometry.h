#include <vector>

#ifndef POINT_H
#define POINT_H

/*! \class Point
A class to represent a point in space
*/
class Point{
	//! private floats are used to represent the coordinates
	float x; /*!< x coordinate */
	float y; /*!< y coordinate */
	float z; /*!< z coordinate */

public:
	//! Accessor function to get the x coordinate of point
	float getX();
	//! Accessor function to get the y coordinate of point
	float getY();
	//! Accessor function to get the z coordinate of point
	float getZ();
  
  	void setX(float x);
	//! Accessor function to get the y coordinate of point
	void setY(float y);
	//! Accessor function to get the z coordinate of point
	void setZ(float z);
  	//! Accessor function to get the array of coordinates of point
	float* getArrayCoors();
};

#endif

#ifndef LINE_H
#define LINE_H

/*! \class Line 
A class to represent a line in space
*/
class Line{
	//! two private objects of class point are instantiated to represent the endpoints of line
	Point p1;
	Point p2;

public:
	//! Accessor function to get the first end point
	Point getFirstPoint();
	//! Accessor function to get the second end point
	Point getSecondPoint();
	//! Accessor function to get the array of end points
	Point* getArrayPoints();
	
  	void setFirstPoint(Point p1);
    void setSecondPoint(Point p2);
};

#endif

#ifndef PLANE_H
#define PLANE_H

/*! \class Plane
A class to represent a plane in space
*/
class Plane{
	//! eqaution of plane : ax + by + cz + d = 0, therefore a plane can be defined by the coefficients a,b,c,d
	float a,b,c,d;

public:
	//! Accessor function to get a
	float getA();
	//! Accessor function to get b
	float getB();
	//! Accessor function to get c
	float getC();
	//! Accessor function to get d
	float getD();
	//! Accessor function to get array of lines
	float* getArrayABCD();
  
  	void setA(float a);
    void setB(float b);
    void setC(float c);
    void setD(float d);
};

#endif

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
  
  	void setPlane(Plane p);
  	void addLine(Line l);

};

#endif