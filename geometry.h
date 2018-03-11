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

/*! \class Plane
A class to represent a plane in space
*/
class Plane{
	//! two private objects of class line are instantiated to represent the lines of plane
	Line l1;
	Line l2;

public:
	//! Accessor function to get the first line
	Line getFirstLine();
	//! Accessor function to get the second line
	Line getSecondLine();
	//! Accessor function to get array of lines
	Line* getArrayLines();
  
  	void setFirstLine(Line l1);
    void setSecondLine(Line l2);
};