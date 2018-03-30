#include <QApplication>
#include <startScreen.h>
#include <fileParser.h>
#include "twoDModelOutputTool.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    
    //startScreen screen;
 	//screen.show();
    MyQGraphicsView view;

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

	TwoDView _2Dview;
	_2Dview.setPoints(&p[0]);
	_2Dview.setLines(&l[0]);

	_2Dview.setPointSize(8);
	_2Dview.setLineSize(12);

	TwoDModel model2D;

	model2D.setFrontView(_2Dview);
	model2D.setTopView(_2Dview);
	model2D.setSideView(_2Dview);

	ThreeDModel model;

	model.setPoints(&p[0]);
	model.setLines(&l[0]);
	model.setPlanes(&pl[0]);
	
	model.setPointSize(8);
	model.setLineSize(12);
	model.setPlaneSize(6);

	TwoDModelGenerator generator(model);

    twoDModelOutputTool tool(model2D, &view);

    tool.drawModel();

    //view.show();

    return a.exec();
}