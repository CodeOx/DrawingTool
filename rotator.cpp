#include "Rotator.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#define pi 3.14159265

void Rotator::setThreeDModel(ThreeDModel model){
	this->model = model;
}

Point rotatePointAboutX(Point p, float angle){
	Point newPoint;

	float oldX,newX,oldY,newY,oldZ,newZ;
	oldX = p.getX();
	oldY = p.getY();
	oldZ = p.getZ();
	newX = oldX;
	newY = cos(angle*pi/180)*oldY - sin(angle*pi/180)*oldZ;
	newZ = sin(angle*pi/180)*oldY + cos(angle*pi/180)*oldZ;

	newPoint.setX(newX);
	newPoint.setY(newY);
	newPoint.setZ(newZ); 

	return newPoint;
}

Point rotatePointAboutY(Point p, float angle){
	Point newPoint;

	float oldX,newX,oldY,newY,oldZ,newZ;
	oldX = p.getX();
	oldY = p.getY();
	oldZ = p.getZ();
	newX = cos(angle*pi/180)*oldX + sin(angle*pi/180)*oldZ;
	newY = oldY;
	newZ = -sin(angle*pi/180)*oldX + cos(angle*pi/180)*oldZ;

	newPoint.setX(newX);
	newPoint.setY(newY);
	newPoint.setZ(newZ); 

	return newPoint;
}

Point rotatePointAboutZ(Point p, float angle){
	Point newPoint;

	float oldX,newX,oldY,newY,oldZ,newZ;
	oldX = p.getX();
	oldY = p.getY();
	oldZ = p.getZ();
	newX = cos(angle*pi/180)*oldX - sin(angle*pi/180)*oldY;
	newY = sin(angle*pi/180)*oldX + cos(angle*pi/180)*oldY;
	newZ = oldZ;

	newPoint.setX(newX);
	newPoint.setY(newY);
	newPoint.setZ(newZ); 

	return newPoint;
}


Point* rotatePointsAboutX(Point* points, int size, float angle){
	Point* rotatedPoints = (Point*)malloc (size * sizeof(Point));
	for(int i = 0; i < size; i++){
		Point p = *points;
		Point newPoint;
		newPoint = rotatePointAboutX(p,angle);
		rotatedPoints[i] = newPoint;
		points++;
	}
	return rotatedPoints;
}

Point* rotatePointsAboutY(Point* points, int size, float angle){
	Point* rotatedPoints = (Point*)malloc (size * sizeof(Point));
	for(int i = 0; i < size; i++){
		Point p = *points;
		Point newPoint;
		newPoint = rotatePointAboutY(p,angle);
		rotatedPoints[i] = newPoint;
		points++;
	}
	return rotatedPoints;
}

Point* rotatePointsAboutZ(Point* points, int size, float angle){
	Point* rotatedPoints = (Point*)malloc (size * sizeof(Point));
	for(int i = 0; i < size; i++){
		Point p = *points;
		Point newPoint;
		newPoint = rotatePointAboutZ(p,angle);
		rotatedPoints[i] = newPoint;
		points++;
	}
	return rotatedPoints;
}

Line* rotateLinesAboutX(Line* lines,int size,float angle){
	Line* rotatedLines = (Line*)malloc (size * sizeof(Line));
	for(int i = 0; i < size; i++){
		Line l = *lines;
		Line newLine;
		newLine.setFirstPoint(rotatePointAboutX(l.getFirstPoint(),angle));
		newLine.setSecondPoint(rotatePointAboutX(l.getSecondPoint(),angle));
		rotatedLines[i] = newLine;
		lines++;
	}
	return rotatedLines;
}

Line* rotateLinesAboutY(Line* lines,int size,float angle){
	Line* rotatedLines = (Line*)malloc (size * sizeof(Line));
	for(int i = 0; i < size; i++){
		Line l = *lines;
		Line newLine;
		newLine.setFirstPoint(rotatePointAboutY(l.getFirstPoint(),angle));
		newLine.setSecondPoint(rotatePointAboutY(l.getSecondPoint(),angle));
		rotatedLines[i] = newLine;
		lines++;
	}
	return rotatedLines;
}

Line* rotateLinesAboutZ(Line* lines,int size,float angle){
	Line* rotatedLines = (Line*)malloc (size * sizeof(Line));
	for(int i = 0; i < size; i++){
		Line l = *lines;
		Line newLine;
		newLine.setFirstPoint(rotatePointAboutZ(l.getFirstPoint(),angle));
		newLine.setSecondPoint(rotatePointAboutZ(l.getSecondPoint(),angle));
		rotatedLines[i] = newLine;
		lines++;
	}
	return rotatedLines;
}


/*Point* Rotator::debug(Point* p, int size, float angle){
	Point* newPoint;
	newPoint = rotatePointsAboutX(p,size,angle);
	return newPoint;
}*/


ThreeDModel Rotator::rotate(ThreeDModel model, std::string axis, float angle){
	std::string X("x");
	std::string Y("y");
	std::string Z("z");
	//std::cout << "enter";
	ThreeDModel newModel;
	Point* oldPoints = model.getPoints();
	Line* oldLines = model.getLines();
	Point* newPoints;
	Line* newLines;

	if(axis.compare(X) != 0){
		//std::cout << "enter";
		newPoints = rotatePointsAboutX(oldPoints,model.getPointSize(),angle);
		newLines = rotateLinesAboutX(oldLines,model.getLineSize(),angle);
	}

	if(axis.compare(Y) != 0){
		newPoints = rotatePointsAboutY(oldPoints,model.getPointSize(),angle);
		newLines = rotateLinesAboutY(oldLines,model.getLineSize(),angle);
	}

	if(axis.compare(Z) != 0){
		newPoints = rotatePointsAboutZ(oldPoints,model.getPointSize(),angle);
		newLines = rotateLinesAboutZ(oldLines,model.getLineSize(),angle);
	}

	newModel.setPoints(newPoints);
	newModel.setLines(newLines);
	newModel.setPointSize(model.getPointSize());
	newModel.setLineSize(model.getLineSize());

	return newModel;
}

