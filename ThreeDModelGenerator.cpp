#include "ThreeDModelGenerator.h"

ThreeDModelGenerator::ThreeDModelGenerator(TwoDModel model){
	this->model = model;
}

ThreeDModel ThreeDModelGenerator::output(){
	possibleVertices = PossibleVerticesConstructor();
	possibleEdges = PossibleEdgesConstructor();
	possibleSurfaces = PossibleSurfacesConstructor();

	ThreeDModel model;

	

	return model;
}