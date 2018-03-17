#include "Lists.h"

void PointList::getPoints(){
	return points;
}

void PointList::getSize(){
	return size;
}

void PointList::setPoints(Point* points){
	this->points = points;
}

void PointList::setSize(int size){
	this->size = size;
}



void LineList::getLines(){
	return lines;
}

void LineList::getSize(){
	return size;
}

void LineList::setlines(line* lines){
	this->lines = lines;
}

void LineList::setSize(int size){
	this->size = size;
}



void planeList::getplanes(){
	return planes;
}

void planeList::getSize(){
	return size;
}

void planeList::setplanes(plane* planes){
	this->planes = planes;
}

void planeList::setSize(int size){
	this->size = size;
}



PlaneWithLines* planeWithLinesList::getPlaneWithLines(){
	return planeWithLines;
}

int planeWithLinesList::getSize(){
	return size;
}

void planeWithLinesList::setPlaneWithLines(PlaneWithLines* p){
	this->planeWithLines = p;
}

void setSize(int size){
	this->size = size;
}



Plane PlaneWithLines::getPlane(){
	return plane;
}

Line* PlaneWithLines::getArrayLines(){
	return &lines[0];
}

int PlaneWithLines::getNumLines(){
	return lines.size();
}

void PlaneWithLines::setPlane(Plane p){
	this->plane = p;
}

void PlaneWithLines::addLine(Line l){
	lines.push_back(l);
}

LineList PlaneWithLines::getLines(){
	LineList l;
	l.setlines(&lines[0]);
	l.setSize(lines.size());

	return l;
}