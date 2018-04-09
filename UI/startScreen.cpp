#include "startScreen.h"
#include "../debug.h"
#include <iostream>

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

		connect(view3D.rotateX, SIGNAL (clicked()), this, SLOT (rotateXClicked()));
		connect(view3D.rotateY, SIGNAL (clicked()), this, SLOT (rotateYClicked()));
		connect(view3D.rotateZ, SIGNAL (clicked()), this, SLOT (rotateZClicked()));

		connect( view3D.horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(setRotationAngle(int)) );
	}

void startScreen::setRotationAngle(int angle){
	rotateAngle = angle;
}

void startScreen::button1Clicked(bool checked)
{
 	filename = openFile3D->openFile();
 	fileOpened3D();
}

void startScreen::button2Clicked(bool checked)
{
 	filename = openFile2D->openFile();
 	fileOpened2D();
}

void startScreen::rotateXClicked(){
	tool3D->rotate("x",rotateAngle);
}

void startScreen::rotateYClicked(){
	tool3D->rotate("y",rotateAngle);
}

void startScreen::rotateZClicked(){
	tool3D->rotate("z",rotateAngle);
}

void startScreen::fileOpened3D()
{	
	model3D = parser._3DModelInput(filename);

	//***3D********** model description begins **************/3D3D/

/*	Point p[8];
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

	model2D.setFrontView(_2Dview);
	model2D.setTopView(_2Dview);
	model2D.setSideView(_2Dview);

	model3D.setPoints(p);
	model3D.setLines(l);
	model3D.setPlanes(pl);
	
	model3D.setPointSize(8);
	model3D.setLineSize(12);
	model3D.setPlaneSize(6);*/

	//************* model description ends **************//

	TwoDModelGenerator twoDgenerator(model3D);
	model2D = twoDgenerator.output();

	tool3D = new threeDModelOutputTool(model3D, &view3D);
	view3D.reset();
	tool3D->drawModel();
	view3D.show();

	twoDModelOutputTool tool2D(model2D, &view2D);
	view2D.reset();
    tool2D.drawModel();
}

void startScreen::fileOpened2D()
{	
	model2D = parser._2DModelInput(filename);
	
	//************* model description begins **************//

	/*Point p[8];
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

	Point fvp[4];
	fvp[0] = p[0];
	fvp[1] = p[1];
	fvp[2] = p[2];
	fvp[3] = p[4];

	Line fvl[4];
	fvl[0] = l[0];
	fvl[1] = l[1];
	fvl[2] = l[6];
	fvl[3] = l[8];

	TwoDView fv;
	fv.setPoints(&fvp[0]);
	fv.setLines(&fvl[0]);
	fv.setPointSize(4);
	fv.setLineSize(4);

	Point tvp[4];
	tvp[0] = p[0];
	tvp[1] = p[2];
	tvp[2] = p[3];
	tvp[3] = p[6];

	Line tvl[4];
	tvl[0] = l[1];
	tvl[1] = l[2];
	tvl[2] = l[9];
	tvl[3] = l[11];

	TwoDView tv;
	tv.setPoints(&tvp[0]);
	tv.setLines(&tvl[0]);
	tv.setPointSize(4);
	tv.setLineSize(4);

	Point svp[4];
	svp[0] = p[0];
	svp[1] = p[1];
	svp[2] = p[3];
	svp[3] = p[5];

	Line svl[4];
	svl[0] = l[0];
	svl[1] = l[2];
	svl[2] = l[7];
	svl[3] = l[10];

	TwoDView sv;
	sv.setPoints(&svp[0]);
	sv.setLines(&svl[0]);
	sv.setPointSize(4);
	sv.setLineSize(4);

	model2D.setFrontView(fv);
	model2D.setTopView(tv);
	model2D.setSideView(sv);*/

	//************* model description ends **************//


	//*****************fvafvv*****************************//

/*	TwoDModel model;
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
	model.setSideView(side);*/

	//******************************************************//


	ThreeDModelGenerator threeDgenerator(model2D);
	threeDgenerator.setRemovePoints(parser.getRemovePoints(filename));
	model3D = threeDgenerator.output();
	std::cout << model3D.getPointSize() << std::endl;

	tool3D = new threeDModelOutputTool(model3D, &view3D);
	view3D.reset();
	tool3D->drawModel();
	view3D.show();

	twoDModelOutputTool tool2D(model2D, &view2D);
	view2D.reset();
    tool2D.drawModel();
}