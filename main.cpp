#include <iostream>
#include "TwoDModelGenerator.h"

using namespace std;

int main(){
	cout<<"input 3d model is a cube"<<endl;
	cout<<"points : (0,0,0); (0,0,1); (0,1,0); (1,0,0); (0,1,1); (1,0,1); (1,1,0); (1,1,1)"<<endl;

	Point p[8];
	p[0].setX(0);
	p[0].setY(0);
	p[0].setZ(0);

	p[1].setX(1);
	p[1].setY(0);
	p[1].setZ(0);

	p[2].setX(0);
	p[2].setY(1);
	p[2].setZ(0);

	p[3].setX(0);
	p[3].setY(0);
	p[3].setZ(1);

	p[4].setX(1);
	p[4].setY(1);
	p[4].setZ(0);

	p[5].setX(1);
	p[5].setY(0);
	p[5].setZ(1);

	p[6].setX(0);
	p[6].setY(1);
	p[6].setZ(1);

	p[7].setX(1);
	p[7].setY(1);
	p[7].setZ(1);

	Line l[12];

	l[0].setFirstPoint(p[0]);
	l[0].setSecondPoint(p[1]);

	l[1].setFirstPoint(p[0]);
	l[1].setSecondPoint(p[2]);

	l[2].setFirstPoint(p[0]);
	l[2].setSecondPoint(p[3]);

	l[3].setFirstPoint(p[7]);
	l[3].setSecondPoint(p[6]);

	l[4].setFirstPoint(p[7]);
	l[4].setSecondPoint(p[5]);

	l[5].setFirstPoint(p[7]);
	l[5].setSecondPoint(p[4]);

	l[6].setFirstPoint(p[1]);
	l[6].setSecondPoint(p[4]);

	l[7].setFirstPoint(p[1]);
	l[7].setSecondPoint(p[5]);

	l[8].setFirstPoint(p[2]);
	l[8].setSecondPoint(p[4]);

	l[9].setFirstPoint(p[2]);
	l[9].setSecondPoint(p[6]);

	l[10].setFirstPoint(p[3]);
	l[10].setSecondPoint(p[5]);

	l[11].setFirstPoint(p[3]);
	l[11].setSecondPoint(p[6]);

	Plane pl[6];

	ThreeDModel model;

	model.setPoints(&p[0]);
	model.setLines(&l[0]);
	model.setPlanes(&pl[0]);
	
	model.setPointSize(8);
	model.setLineSize(12);
	model.setPlaneSize(6);

	TwoDModelGenerator generator(model);

	cout<<"output model:"<<endl;
	TwoDModel m = generator.output();
	Point* p1 = m.getFrontView().getPoints();

	for(int i = 0; i < m.getFrontView().getPointSize(); i++){
		cout<<(p1->getX())<<" ";
		p1++;
	}

	return 0;
}