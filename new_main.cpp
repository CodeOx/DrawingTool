#include <iostream>
#include <string>
#include "TwoDModelGenerator.h"
#include "ThreeDModelGenerator.h"
#include "FileParser.h"

using namespace std;

int main(){
	TwoDModel model;
	TwoDView front;
	TwoDView top;
	TwoDView side;
	
	Point frontPoints[3];
	frontPoints[0].setX(0);
	frontPoints[0].setY(0);
	frontPoints[0].setZ(0);

	frontPoints[1].setX(0);
	frontPoints[1].setY(0);
	frontPoints[1].setZ(1);

	frontPoints[2].setX(0);
	frontPoints[2].setY(1);
	frontPoints[2].setZ(0);

	Point topPoints[3];
	topPoints[0].setX(0);
	topPoints[0].setY(0);
	topPoints[0].setZ(0);

	topPoints[1].setX(1);
	topPoints[1].setY(0);
	topPoints[1].setZ(0);

	topPoints[2].setX(0);
	topPoints[2].setY(1);
	topPoints[2].setZ(0);

	Point sidePoints[3];
	sidePoints[0].setX(0);
	sidePoints[0].setY(0);
	sidePoints[0].setZ(0);

	sidePoints[1].setX(0);
	sidePoints[1].setY(0);
	sidePoints[1].setZ(1);

	sidePoints[2].setX(0);
	sidePoints[2].setY(1);
	sidePoints[2].setZ(0);

	Line frontLines[3];
	frontLines[0].setFirstPoint(frontPoints[0]);
	frontLines[0].setSecondPoint(frontPoints[1]);

	frontLines[1].setFirstPoint(frontPoints[1]);
	frontLines[1].setSecondPoint(frontPoints[2]);

	frontLines[2].setFirstPoint(frontPoints[2]);
	frontLines[2].setSecondPoint(frontPoints[0]);

	Line topLines[3];
	topLines[0].setFirstPoint(topPoints[0]);
	topLines[0].setSecondPoint(topPoints[1]);

	topLines[1].setFirstPoint(topPoints[1]);
	topLines[1].setSecondPoint(topPoints[2]);

	topLines[2].setFirstPoint(topPoints[2]);
	topLines[2].setSecondPoint(topPoints[0]);

	Line sideLines[3];
	sideLines[0].setFirstPoint(sidePoints[0]);
	sideLines[0].setSecondPoint(sidePoints[1]);

	sideLines[1].setFirstPoint(sidePoints[1]);
	sideLines[1].setSecondPoint(sidePoints[2]);

	sideLines[2].setFirstPoint(sidePoints[2]);
	sideLines[2].setSecondPoint(sidePoints[0]);

	front.setPoints(&frontPoints[0]);
	front.setLines(&frontLines[0]);

	top.setPoints(&topPoints[0]);
	top.setLines(&topLines[0]);

	side.setPoints(&sidePoints[0]);
	side.setLines(&sideLines[0]);

	model.setFrontView(front);
	model.setTopView(top);
	model.setSideView(side);

	ThreeDModelGenerator g;
	g.getTwoDModel(model);
	PointList list;
	list = g.PossibleVerticesConstructor();
	Point* p = list.getPoints();
	std::cout << list.getSize() << std::endl;
	for(int i = 0; i < list.getSize(); i++){
		Point n = *p;
		cout << n.getX() << "\t" << n.getY() << "\t" << n.getZ() << endl;
		p++;
	}
}
