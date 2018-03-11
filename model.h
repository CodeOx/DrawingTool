#include "view.h"

#ifndef TWODMODEL_H
#define TWODMODEL_H

/*! \class TwoDModel
A class representing a 2D model containing the three views
*/
class TwoDModel{

	TwoDView frontView; /*< frontView is an object of TwoDView class */
	TwoDView topView; /*< topView is an object of TwoDView class */
	TwoDView sideView; /*< sideView is an object of TwoDView class */

public:
	//! Accessor function to get the front view
	TwoDView getFrontView();
	//! Accessor function to get the top view
	TwoDView getTopView();
	//! Accessor function to get the side view
	TwoDView getSideView();

	void setFrontView(TwoDView v);
	void setTopView(TwoDView v);
	void setSideView(TwoDView v);
};

#endif

#ifndef THREEDMODEL_H
#define THREEDMODEL_H

/*! \class ThreeDModel
A class representing a 3D model containing the vertices, edges and surfaces
*/
class ThreeDModel{

	Point* points; /*< points represent the vertices */ 
	int pointSize = 0;
	Line* lines; /*< lines represent the edges */
	int lineSize = 0;
	Plane* planes; /*< planes represent the surfaces */
	int planeSize = 0;

public:
	//! Accessor function to get the vertices
	Point* getPoints();
	//! Accessor function to get the lines
	Line* getLines();
	//! Accessor function to get the surfaces
	Plane* getPlanes();

	void setPoints(Point* p);
	void setLines(Line* l);
	void setPlanes(Plane* p);
	
	int getPointSize();
	int getLineSize();
	int getPlaneSize();
	
	void setPointSize(int s);
	void setLineSize(int s);
	void setPlaneSize(int s);
};

#endif