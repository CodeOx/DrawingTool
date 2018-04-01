#include "startScreen.h"

startScreen::startScreen(QWidget *parent) :
	QWidget(parent)
	{
		// Set size of the window
		setFixedSize(800, 300);

		// Create and position the button
		button1 = new QPushButton("3D to 2D conversion", this);
		button1->setGeometry(100, 75, 200, 150);

		button2 = new QPushButton("2D to 3D conversion", this);	
		button2->setGeometry(500, 75, 200, 150);

		openFile3D = new QFileDialogTester();
		openFile2D = new QFileDialogTester();

		connect(button1, SIGNAL (clicked(bool)), this, SLOT (button1Clicked(bool)));
		connect(button2, SIGNAL (clicked(bool)), this, SLOT (button2Clicked(bool)));
		connect(openFile3D, SIGNAL (fileOpened()), this, SLOT (fileOpened3D()));
		connect(openFile2D, SIGNAL (fileOpened()), this, SLOT (fileOpened2D()));
	}

void startScreen::button1Clicked(bool checked)
{
 	filename = openFile3D->openFile();
}

void startScreen::button2Clicked(bool checked)
{
 	filename = openFile2D->openFile();
}

void startScreen::fileOpened3D()
{	
	//perform file parsing here
	//view.setThreeDModel(model);

	//************* model description begins **************//

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

	model.setPoints(p);
	model.setLines(l);
	model.setPlanes(pl);
	
	model.setPointSize(8);
	model.setLineSize(12);
	model.setPlaneSize(6);

	TwoDModelGenerator twoDgenerator(model);
	model2D = twoDgenerator.output();

	//************* model description ends **************//

	threeDModelOutputTool tool3D(model, &view3D);
	tool3D.drawModel();

	twoDModelOutputTool tool2D(model2D, &view2D);
    tool2D.drawModel();
}

void startScreen::fileOpened2D()
{	
	//perform file parsing here
	//view.setThreeDModel(model);
	
	//************* model description begins **************//

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

	model.setPoints(p);
	model.setLines(l);
	model.setPlanes(pl);
	
	model.setPointSize(8);
	model.setLineSize(12);
	model.setPlaneSize(6);

	TwoDModelGenerator twoDgenerator(model);
	model2D = twoDgenerator.output();

	//************* model description ends **************//

	threeDModelOutputTool tool3D(model, &view3D);
	tool3D.drawModel();

	twoDModelOutputTool tool2D(model2D, &view2D);
    tool2D.drawModel();
}