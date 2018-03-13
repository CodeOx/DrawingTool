#include "stdlib.h"
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
	float* ar = (float*)malloc (3 * sizeof(float));
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
	Point* ar = (Point*)malloc (2 * sizeof(Point));
	ar[0] = p1;
	ar[1] = p2;
	return ar;
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
	float* ar = (float*)malloc (4 * sizeof(float));
	ar[0] = a;
	ar[1] = b;
	ar[2] = c;
	ar[3] = d;
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