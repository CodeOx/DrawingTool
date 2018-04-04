#include "ThreeDModelGenerator.h"
#include <iostream>

ThreeDModelGenerator::ThreeDModelGenerator(TwoDModel model){
	this->model = model;
}

ThreeDModel ThreeDModelGenerator::output(){
	this->PossibleVerticesConstructor();
	
	std::cout<< std::endl<< std::endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << possibleVertices.getSize() << std::endl;
	this->PossibleEdgesConstructor();
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