#include "twoDModelOutputTool.h"
#include <QTextStream>
#include <QDebug>
#include <string> 

Point getMinCoordinates(TwoDView view){
	Point p;

	Point* pointList = view.getPoints();

	float x = pointList->getX();
	float y = pointList->getY();
	float z = pointList->getZ();

	for(int i = 0; i < view.getPointSize(); i++){
		if (pointList->getX() < x){
			x = pointList -> getX();
		}

		if (pointList->getY() < y){
			y = pointList -> getY();
		}

		if (pointList->getZ() < z){
			z = pointList -> getZ();
		}

		pointList++;
	}

	p.setX(x);
	p.setY(y);
	p.setZ(z);

	return p;
}

Point getMaxCoordinates(TwoDView view){
	Point p;

	Point* pointList = view.getPoints();

	float x = pointList->getX();
	float y = pointList->getY();
	float z = pointList->getZ();

	for(int i = 0; i < view.getPointSize(); i++){
		if (pointList->getX() > x){
			x = pointList -> getX();
		}

		if (pointList->getY() > y){
			y = pointList -> getY();
		}

		if (pointList->getZ() > z){
			z = pointList -> getZ();
		}

		pointList++;
	}

	p.setX(x);
	p.setY(y);
	p.setZ(z);

	return p;
}

float max(float v1, float v2, float v3){
	if (v1 > v2){
		if (v1 > v3){
			return v1;
		}
		return v3;
	}
	else{
		if (v2 > v3){
			return v2;
		}
		return v3;
	}
}

twoDModelOutputTool::twoDModelOutputTool(TwoDModel model){
	this->model = model;
	
	this->frontView = model.getFrontView();
	this->topView = model.getTopView();
	this->sideView = model.getSideView();
}

twoDModelOutputTool::twoDModelOutputTool(TwoDModel model, twoDOutputWidget* view){
	this->model = model;
	this->view = view;

	this->frontView = model.getFrontView();
	this->topView = model.getTopView();
	this->sideView = model.getSideView();
}

void twoDModelOutputTool::translateOrigin(){
	originShiftAmountFrontView = getMinCoordinates(frontView);
	originShiftAmountTopView = getMinCoordinates(topView);
	originShiftAmountSideView = getMinCoordinates(sideView);
}

void twoDModelOutputTool::normalise(){
	Point maxFrontView = getMaxCoordinates(frontView);
	Point minFrontView = originShiftAmountFrontView;
	float rangeFrontViewX = maxFrontView.getX() - minFrontView.getX();
	float rangeFrontViewY = maxFrontView.getY() - minFrontView.getY();
	float rangeFrontViewZ = maxFrontView.getZ() - minFrontView.getZ();

	float rangeFrontView = max(rangeFrontViewX, rangeFrontViewY, rangeFrontViewZ);

	scaleAmountFrontView = (finalScale/rangeFrontView);



	Point maxTopView = getMaxCoordinates(topView);
	Point minTopView = originShiftAmountTopView;
	float rangeTopViewX = maxTopView.getX() - minTopView.getX();
	float rangeTopViewY = maxTopView.getY() - minTopView.getY();
	float rangeTopViewZ = maxTopView.getZ() - minTopView.getZ();

	float rangeTopView = max(rangeTopViewX, rangeTopViewY, rangeTopViewZ);

	scaleAmountTopView = (finalScale/rangeTopView);



	Point maxSideView = getMaxCoordinates(sideView);
	Point minSideView = originShiftAmountSideView;
	float rangeSideViewX = maxSideView.getX() - minSideView.getX();
	float rangeSideViewY = maxSideView.getY() - minSideView.getY();
	float rangeSideViewZ = maxSideView.getZ() - minSideView.getZ();

	float rangeSideView = max(rangeSideViewX, rangeSideViewY, rangeSideViewZ);

	scaleAmountSideView = (finalScale/rangeSideView);

}

void twoDModelOutputTool::drawModel(){

	translateOrigin();
	normalise();

	//drawing front view
	Line* frontViewLines = frontView.getLines();
	for (int i = 0; i < frontView.getLineSize(); i++){
		Point p1 = frontViewLines -> getFirstPoint();
		Point p2 = frontViewLines -> getSecondPoint();

		/*std::string a = std::to_string(p1.getX()) + ", " + std::to_string(p1.getY()) + ", " + std::to_string(p1.getZ()) + "\n";
		std::string b = a + std::to_string(p2.getX()) + ", " + std::to_string(p2.getY()) + ", " + std::to_string(p2.getZ()) + "\n";
		QTextStream out(stdout);
		out << QString::fromStdString(b);*/

		float p1NormalisedX = ((p1.getX() - originShiftAmountFrontView.getX())*scaleAmountFrontView) + 50.0;
		float p1NormalisedY = ((p1.getY() - originShiftAmountFrontView.getY())*scaleAmountFrontView) + 150.0;
		float p2NormalisedX = ((p2.getX() - originShiftAmountFrontView.getX())*scaleAmountFrontView) + 50.0;
		float p2NormalisedY = ((p2.getY() - originShiftAmountFrontView.getY())*scaleAmountFrontView) + 150.0;

		view -> setp1(p1NormalisedX, p1NormalisedY);
		view -> setp2(p2NormalisedX, p2NormalisedY);

		view -> drawOutput2D();

		frontViewLines++;
	}

	//drawing top view
	Line* topViewLines = topView.getLines();
	for (int i = 0; i < topView.getLineSize(); i++){
		Point p1 = topViewLines -> getFirstPoint();
		Point p2 = topViewLines -> getSecondPoint();

		float p1NormalisedX = ((p1.getY() - originShiftAmountFrontView.getY())*scaleAmountFrontView) + 350.0;
		float p1NormalisedY = ((p1.getZ() - originShiftAmountFrontView.getZ())*scaleAmountFrontView) + 150.0;
		float p2NormalisedX = ((p2.getY() - originShiftAmountFrontView.getY())*scaleAmountFrontView) + 350.0;
		float p2NormalisedY = ((p2.getZ() - originShiftAmountFrontView.getZ())*scaleAmountFrontView) + 150.0;

		view -> setp1(p1NormalisedX, p1NormalisedY);
		view -> setp2(p2NormalisedX, p2NormalisedY);

		view -> drawOutput2D();

		topViewLines++;
	}

	//drawing side view
	Line* sideViewLines = sideView.getLines();
	for (int i = 0; i < sideView.getLineSize(); i++){
		Point p1 = sideViewLines -> getFirstPoint();
		Point p2 = sideViewLines -> getSecondPoint();

		float p1NormalisedX = ((p1.getZ() - originShiftAmountFrontView.getZ())*scaleAmountFrontView) + 650.0;
		float p1NormalisedY = ((p1.getX() - originShiftAmountFrontView.getX())*scaleAmountFrontView) + 150.0;
		float p2NormalisedX = ((p2.getZ() - originShiftAmountFrontView.getZ())*scaleAmountFrontView) + 650.0;
		float p2NormalisedY = ((p2.getX() - originShiftAmountFrontView.getX())*scaleAmountFrontView) + 150.0;

		view -> setp1(p1NormalisedX, p1NormalisedY);
		view -> setp2(p2NormalisedX, p2NormalisedY);

		view -> drawOutput2D();

		sideViewLines++;
	}

	view -> show();
}

Point twoDModelOutputTool::getOriginShiftAmountFrontView(){
	return originShiftAmountFrontView;
}

float twoDModelOutputTool::getScaleAmountFrontView(){
	return scaleAmountFrontView;
}

float twoDModelOutputTool::getFinalScale(){
	return finalScale;
}