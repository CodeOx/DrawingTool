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

bool checkEqualPlanes(Plane p1, Plane p2){
	float ratio1 = p1.getA()/p2.getA();
	float ratio2 = p1.getB()/p2.getB();
	float ratio3 = p1.getC()/p2.getC();
	float ratio4 = p1.getD()/p2.getD();

	if(ratio1 == ratio2 && ratio1 == ratio3 && ratio1 == ratio4){
		return true;
	}

	return false;
}

PlaneWithLines* planeWithLinesListContains(Plane p, PlaneWithLines* plwithln, int size){
	
	for(int i = 0; i< size; i++){
		if(checkEqualPlanes(p, (*plwithln).getPlane())){
			return plwithln;
		}
	}

	return nullptr;
}

planeWithLinesList ThreeDModelGenerator::PossibleSurfacesConstructor(LineList possibleEdges){
	Line* lines = possibleEdges.getlines();
	int numLines = possibleEdges.getSize();

	std::vector<PlaneWithLines> list;

	for(int i = 0; i < numLines-1; i++){
		
		Line* tempLines = lines+1;
		
		for(int j = 1; j < numLines; j++){
			
			if(checkIntersecting(*lines, *tempLines)){
				Plane p = getPlane(*lines, *tempLines);
				PlaneWithLines* originalPlane = planeWithLinesListContains(p,&list[0],list.size());
				
				if(originalPlane == nullptr){
					PlaneWithLines newPlaneWithLines;
					newPlaneWithLines.setPlane(p);
					newPlaneWithLines.addLine(*lines);
					newPlaneWithLines.addLine(*tempLines);
					list.push_back(newPlaneWithLines);
				}
				else{
					(*originalPlane).addLine(*tempLines);
					(*originalPlane).addLine(*lines);
				}
			
			}

			tempLines++;

		}
		
		lines++;
	}

	/*
		Loop to remove duplcate lines here
	*/

	planeWithLinesList arr;
	arr.setPlaneWithLines(&list[0]);
	arr.setSize(list.size());

	return arr; 
}