#include "ThreeDModelGenerator.h"

ThreeDModelGenerator::ThreeDModelGenerator(TwoDModel model){
	this->model = model;
}

ThreeDModel ThreeDModelGenerator::output(){
	possibleVertices = PossibleVerticesConstructor();
	possibleEdges = PossibleEdgesConstructor();
	//possibleSurfaces = PossibleSurfacesConstructor();

	ThreeDModel model;

	model.setPoints(possibleVertices.getPoints());
	model.setPointSize(possibleVertices.getSize());

	model.setLines(possibleEdges.getLines());
	model.setLineSize(possibleEdges.getSize());

	//model.setPlanes(possibleSurfaces.getPlanes());
	//model.setPlaneSize(possibleSurfaces.getSize());

	return model;
}