#include "ThreeDModelGenerator.h"
#include <vector>

bool checkEqualPoints(Point p1, Point p2){
	if(p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ()){
		return true;
	}
	return false;
}

bool checkIntersecting(Line l1, Line l2){
	if(checkEqualPoints(l1.getFirstPoint(), l2.getFirstPoint()))
		return true;
	if(checkEqualPoints(l1.getFirstPoint(), l2.getSecondPoint()))
		return true;
	if(checkEqualPoints(l1.getSecondPoint(), l2.getFirstPoint()))
		return true;
	if(checkEqualPoints(l1.getSecondPoint(), l2.getSecondPoint()))
		return true;

	return false;
}

Plane getPlane(Line l1, Line l2){

}

PlaneWithLinesList ThreeDModelGenerator::PossibleSurfacesConstructor(LineList possibleEdges){
	Line* lines = possibleEdges.getLines();
	int numLines = possibleEdges.getSize();

	std::vector<PlaneWithLinesList> list;

	for(int i = 0; i < numLines-1; i++){
		
		Line* tempLines = lines+1;
		
		for(int j = 1; j < numLines; j++){
			
			if(checkIntersecting(*lines, *tempLines)){
				Plane p = getPlane(*lines, *tempLines);
			}

			tempLines++;

		}
		
		lines++;
	}
}