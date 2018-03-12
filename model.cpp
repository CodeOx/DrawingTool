#include "model.h"

TwoDView TwoDModel::getFrontView(){
	return frontView;
}

TwoDView TwoDModel::getTopView(){
	return topView;
}	

TwoDView TwoDModel::getSideView(){
	return sideView;
}

void TwoDModel::setFrontView(TwoDView v){
	this.frontView = v;
}

void TwoDModel::setTopView(TwoDView v){
	this.topView = v;
}

void TwoDModel::setSideView(TwoDView v){
	this.sideView = v;
}


Point* ThreeDModel::getPoints(){
	return points;
}

Line* ThreeDModel::getLines(){
	return lines;
}

Planes* ThreeDModel::getPlanes(){
	return planes;
}

void ThreeDModel::setPoints(Point* p){
	this.points = p;
}

void ThreeDModel::setLines(Line* l){
	this.lines = l;
}

void ThreeDModel::setPlanes(Plane* p){
	this.planes = p;
}

int ThreeDModel::getPointSize(){
	return pointSize;
}

int ThreeDModel::getLineSize(){
	return lineSize;
}

int ThreeDModel::getPlaneSize(){
	return planeSize;
}

void ThreeDModel::setPointSize(int s){
	this.pointSize += s;
}

void ThreeDModel::setLineSize(int s){
	this.lineSize += s;
}

void ThreeDModel::setPlaneSize(int s){
	this.planeSize += s;
}