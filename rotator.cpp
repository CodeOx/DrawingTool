#include "Rotator.h"
#include <cmath>
#include <string>
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

	return p;
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

	return p;
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

	return p;
}


Point* rotatePointsAboutX(Point* points, int size, float angle){
	Point rotatedPoints[size];
	for(int i = 0; i < size; i++){
		Point p = *points;
		Point newPoint;
		newPoint = rotatePointAboutX(p,angle);
		rotatedPoints[i] = p;
		points++;
	}
	return rotatedPoints;
}

Point* rotatePointsAboutY(Point* points, int size, float angle){
	Point rotatedPoints[size];
	for(int i = 0; i < size; i++){
		Point p = *points;
		Point newPoint;
		newPoint = rotatePointAboutY(p,angle);
		rotatedPoints[i] = p;
		points++;
	}
	return rotatedPoints;
}

Point* rotatePointsAboutZ(Point* points, int size, float angle){
	Point rotatedPoints[size];
	for(int i = 0; i < size; i++){
		Point p = *points;
		Point newPoint;
		newPoint = rotatePointAboutZ(p,angle);
		rotatedPoints[i] = p;
		points++;
	}
	return rotatedPoints;
}

Line* rotateLinesAboutX(Line* lines,int size,float angle){
	Line rotatedLines[size];
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
	Line rotatedLines[size];
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
	Line rotatedLines[size];
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


ThreeDModel Rotator::rotate(ThreeDModel model, std::string axis, float angle){
	std::string X("x");
	std::string Y("y");
	std::string Z("z");

	ThreeDModel newModel;
	Point* oldPoints = model.getPoints();
	Line* oldLines = model.getLines();
	Point* newPoints;
	Line* newLines;

	if(axis.compare(X) != 0){
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