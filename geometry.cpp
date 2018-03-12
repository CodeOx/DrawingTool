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
	this->x = x;
}

void Point::setY(float y){
	this->y = y;
}

void Point::setZ(float z){
	this->z = z;
}

float* Point::getArrayCoors(){
	float ar[3];
	ar[0] = x;
	ar[1] = y;
	ar[2] = z;
	return &ar[0];
}



Point Line::getFirstPoint(){
	return p1;
}

Point Line::getSecondPoint(){
	return p2;
}

Point* Line::getArrayPoints(){
	Point ar[2] = {p1,p2};
	return &ar[0];
}

void Line::setFirstPoint(Point p1){
this->p1 = p1;
}

void Line::setSecondPoint(Point p2){
this->p2 = p2;
}



float Plane::getA(){
	return a;
}

float Plane::getB(){
	return b;
}

float Plane::getC(){
	return c;
}

float Plane::getD(){
	return d;
}

float* Plane::getArrayABCD(){
	float ar[4] = {a,b,c,d};
	return ar;
}

void Plane::setA(float a){
	this->a = a;
}

void Plane::setB(float b){
	this->b = b;
}

void Plane::setC(float c){
	this->c = c;
}

void Plane::setD(float d){
	this->d = d;
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