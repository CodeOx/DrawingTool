#include "view.h"

Point* TwoDView::getPoints(){
	return points;
}

Line* TwoDView::getLines(){
	return lines;
}

void TwoDView::setPoints(Point* p){
	this.points = p;
}

void TwoDView::setLines(Line* l){
	this.lines = l;
}

int TwoDView::getPointSize(){
	return pointSize;
}

int TwoDView::getLineSize(){
	return lineSize;
}

void TwoDView::setPointSize(int s){
	this.pointSize += s;
}

void TwoDView::setLineSize(int s){
	this.lineSize += s;
}
