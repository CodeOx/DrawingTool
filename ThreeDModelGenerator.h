#include "model.h"
#include "Lists.h"

#ifndef THREEDMODELGENERATOR_H
#define THREEDMODELGENERATOR_H

class ThreeDModelGenerator{

	TwoDModel model; /*< Every public function access this object representing the 2D model */
	PointList possibleVertices;
	LineList possibleEdges;
	planeWithLinesList possibleSurfaces;


public:
	//! Input function to get the 2D model
	ThreeDModelGenerator(TwoDModel model);
	//! This function returns a list of possible vertices in a array of point objects
	PointList PossibleVerticesConstructor();
	//! This function returns a list of possible edges in a array of line objects
	LineList PossibleEdgesConstructor();
	//! This function returns a list of possible surfaces in a array of plane objects
	planeWithLinesList PossibleSurfacesConstructor();
	//! This function checks if two given planes are duplicate or not 
	bool DuplicatePlaneChecker(Plane p1, Plane p2);
	//! This function returns a list of possible closed loops in a array of plane objects
	void PossibleClosedLoopFacesConstructor(planeWithLinesList possibleSurfaces);
	//! This function returns a list of possible objects in a array of ThreeDModel objects
	ThreeDModel* PossibleObjectsConstructor();
	//! This function returns a ThreeDModel object after combining possible subobjects
	ThreeDModel PossibleObjectsCombiner(ThreeDModel *);
	//! This function returns the final ThreeDModel object 
	ThreeDModel output();

	void PossibleClosedLoopConstructor(PlaneWithLines possiblePlane);
};

#endif