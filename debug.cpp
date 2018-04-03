#include "debug.h"	

void printPoint(Point p){
	std::cout<<"Point : " << p.getX() << " , " << p.getY() << " , " << p.getZ()<<std::endl; 
}

void printLine(Line l){
	std::cout << "First Point : " << std::endl;
	printPoint(l.getFirstPoint());
	std::cout << "Second Point : " << std::endl;
	printPoint(l.getSecondPoint());
}
