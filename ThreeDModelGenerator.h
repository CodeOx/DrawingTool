#include "model.h"
#include "Lists.h"

#ifndef THREEDMODELGENERATOR_H
#define THREEDMODELGENERATOR_H

class ThreeDModelGenerator{

	TwoDModel model; /*< Every public function access this object representing the 2D model */

public:
	//! Input function to get the 2D model
	void getTwoDModel(TwoDModel model);
	//! This function returns a list of possible vertices in a array of point objects
	Point* PossibleVerticesConstructor();
	//! This function returns a list of possible edges in a array of line objects
	Line* PossibleEdgesConstructor(PointList points);
	//! This function returns a list of possible surfaces in a array of plane objects
	Plane* PossibleSurfacesConstructor();
	//! This function checks if two given planes are duplicate or not 
	bool DuplicatePlaneChecker(Plane p1, Plane p2);
	//! This function returns a list of possible closed loops in a array of plane objects
	Plane* PossibleClosedLoopFacesConstructor();
	//! This function returns a list of possible objects in a array of ThreeDModel objects
	ThreeDModel* PossibleObjectsConstructor();
	//! This function returns a ThreeDModel object after combining possible subobjects
	ThreeDModel PossibleObjectsCombiner(ThreeDModel *);
	//! This function returns the final ThreeDModel object 
	ThreeDModel output();
};

#endif