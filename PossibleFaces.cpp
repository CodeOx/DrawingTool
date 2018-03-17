#include<cmath>
#include "ThreeDModelGenerator.h"

float angleBtwLines(Line l1, Line l2){
	float firstX, firstY, firstZ;
	float secondX, secondY, secondZ, cos_theta; 
	float dotProduct;
	float firstMag;
	float secondMag;
	firstX = l1.getFirstPoint().getX() - l1.getSecondPoint().getX();
	secondX = l2.getFirstPoint().getX() - l2.getSecondPoint().getX();
	firstY = l1.getFirstPoint().getY() - l1.getSecondPoint().getY();
	secondY = l2.getFirstPoint().getX() - l2.getSecondPoint().getX();
	firstZ = l1.getFirstPoint().getZ() - l1.getSecondPoint().getZ();
	secondZ = l2.getFirstPoint().getZ() - l2.getSecondPoint().getZ();
	dotProduct = firstX*secondX + firstY*secondY + firstZ*secondZ;
	firstMag = sqrt(firstX*firstX + firstY*firstY + firstZ*firstZ);
	secondMag = sqrt(secondX*secondX + secondY*secondY + secondZ*secondZ);
	cos_theta = dotProduct/(firstMag * secondMag);
	return acos(cos_theta);
}

float angleBtwPlanes(Plane p1, Plane p2){
	float a1 = p1.getA();
	float b1 = p1.getB();
	float c1 = p1.getC();
	float a2 = p2.getA();
	float b2 = p2.getB();
	float c2 = p2.getC();
	float dotProduct = a1*a2 + b1*b2 + c1*c2;
	float firstMag = sqrt(a1*a1 + b1*b1 + c1*c1);
	float secondMag = sqrt(a2*a2 + b2*b2 + c2*c2);
	float cos_theta = dotProduct/(firstMag * secondMag);
	return acos(cos_theta);
}

bool checkEqualPoints(Point p1, Point p2){
	if(p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ()){
		return true;
	}
	return false;
}

bool checkEqualLines(Line l1, Line l2){
	if(checkEqualPoints(l1.getFirstPoint(), l2.getFirstPoint()) && checkEqualPoints(l1.getSecondPoint(), l2.getSecondPoint())){
		return true;
	}
	return false;
}

bool member(Line l, Line* lines, int count){
	for(int i = 0; i < count; i++){
		if(checkEqualLines(lines[i],l)){
			return true;
		}
	}
	return false;
}

int memberIndex(Line l, Line* lines, int count){
	for(int i = 0; i < count; i++){
		if(checkEqualLines(lines[i],l)){
			return i;
		}
	}
	return -1;
}

LineList getLinesAtPoint(Point p, LineList l){
	Line* lines;
	lines = l.getLines();
	Line resLines[l.getSize()];
	int count = 0;
	for(int i = 0; i < l.getSize(); i++){
		if(checkEqualPoints(lines[i].getFirstPoint(), p) || checkEqualPoints(lines[i].getSecondPoint(), p)){
			if(!(member(lines[i],resLines,count))){
				resLines[count] = lines[i];
			}
		}
	}
	LineList ob;
	ob.setLines(resLines);
	ob.setSize(count);
	return ob;
}

Line getMinLine(Line l, LineList list){
	float min = 100;
	Line minLine;
	int size = list.getSize();
	Line lines[size];
	for(int i = 0; i < size; i++){
		if(angleBtwLines(l,lines[i]) < min){
			min = angleBtwLines(l,lines[i]);
			minLine = l;
		}
	}
	return minLine;
}

void ThreeDModelGenerator::PossibleClosedLoopConstructor(PlaneWithLines possiblePlane){
	//initial line
	Line firstLine = *possiblePlane.getArrayLines(); 
	Line prevLine = *possiblePlane.getArrayLines(); 
	//Array of loop lines
	Line loopLines[possiblePlane.getNumLines()];
	//Array of approached points of each line
	Point approachedPoints[possiblePlane.getNumLines()];
	int loopLinesLen = 0;
	for(int i = 0; i < possiblePlane.getNumLines(); i++){
		LineList l;
		l.setLines(possiblePlane.getArrayLines());
		l.setSize(possiblePlane.getNumLines());
		LineList temp = getLinesAtPoint(prevLine.getSecondPoint(),l);
		Line nextLine = getMinLine(prevLine, temp);
		if(member(nextLine, loopLines, i)){
			//index represents the index where the line is found
			int index = memberIndex(nextLine, loopLines, i);
			//if edge is false edge
			if(index != -1 && checkEqualPoints(approachedPoints[index],prevLine.getSecondPoint())){
				//implement remove function for lineList
				this->possibleEdges.remove(nextLine);
				ThreeDModelGenerator::PossibleSurfacesConstructor(this->possibleEdges);
			}
			else{
				if(checkEqualLines(nextLine,firstLine)){
					break;
				}
			}
		}
		else{
			//update the parameters
			loopLines[loopLinesLen] = nextLine;
			loopLinesLen++;
			prevLine = nextLine;
		}
		
	}
}

void ThreeDModelGenerator::PossibleClosedLoopFacesConstructor(planeWithLinesList possibleSurfaces){
	int size = possibleSurfaces.getSize();
	PlaneWithLines* surfaces;
	surfaces = possibleSurfaces.getPlaneWithLines();
	for(int i = 0; i < size; i++){
		PossibleClosedLoopConstructor(*surfaces);
		surfaces++;
	}

}
