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



void LineList::getlines(){
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