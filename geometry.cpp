#include "geometry.h"

float Point::getX(){
	return x;
}

float Point::getY(){
	return y;
}

float Point::getZ(){
	return z;
}

void Point::setX(float x){
	this.x = x;
}

void Point::setY(float y){
	this.y = y;
}

void Point::setZ(float z){
	this.z = z;
}

float* Point::getArrayCoors(){
	float ar[3];
	ar[0] = x;
	ar[1] = y;
	ar[2] = z;
	return ar;
}



Point Line::getFirstPoint(){
	return p1;
}

Point Line::getSecondPoint(){
	return p2;
}

Point* Line::getArrayPoints(){
	Point ar[2] = {p1,p2};
	return ar;
}

void Line::setFirstPoint(Point p1){
this.p1 = p1;
}

void Line::setSecondPoint(Point p2){
this.p2 = p2;
}



Line Plane::getFirstLine(){
	return l1;
}

Line Plane::getSecondLine(){
	return l2;
}

Line* Plane::getArrayLines(){
	Line ar[2] = {l1,l2};
	return ar;
}

void Plane::setFirstLine(Line l1){
this.l1 = l1;
}

void Plane::setSecondLine(Line l2){
this.l2 = l2;
}