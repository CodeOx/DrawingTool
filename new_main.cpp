#include <iostream>
#include <string>
#include "TwoDModelGenerator.h"
#include "ThreeDModelGenerator.h"
#include "debug.h"

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
	frontPoints[1].setY(1);
	frontPoints[1].setZ(0);

	frontPoints[2].setX(1);
	frontPoints[2].setY(0);
	frontPoints[2].setZ(0);

	Point topPoints[3];
	topPoints[0].setX(0);
	topPoints[0].setY(0);
	topPoints[0].setZ(0);

	topPoints[1].setX(0);
	topPoints[1].setY(0);
	topPoints[1].setZ(1);

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

	sidePoints[2].setX(1);
	sidePoints[2].setY(0);
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
	front.setLineSize(3);
	front.setPointSize(3);

	top.setPoints(&topPoints[0]);
	top.setLines(&topLines[0]);
	top.setLineSize(3);
	top.setPointSize(3);

	side.setPoints(&sidePoints[0]);
	side.setLines(&sideLines[0]);
	side.setLineSize(3);
	side.setPointSize(3);

	model.setFrontView(front);
	model.setTopView(top);
	model.setSideView(side);

	ThreeDModelGenerator g(model);
	//g.PossibleVerticesConstructor();
	//g.PossibleEdgesConstructor();
	ThreeDModel mo = g.output();
	std::cout<<"vzfbvzdgbfx "<< mo.getPointSize() << std::endl;
	printLine(mo.getLines()[0]);

	/*Line* p = list.getLines();
	std::cout << list.getSize() << std::endl;
	for(int i = 0; i < list.getSize(); i++){
		Line n = *p;
		std::cout << "hello" << n.getFirstPoint().getX() << "\t" << n.getFirstPoint().getY() << "\t" << n.getFirstPoint().getZ() << std::endl;
		p++;
	}*/
}
