#include "twoDModelOutputTool.h"

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

twoDModelOutputTool::twoDModelOutputTool(TwoDModel model, MyQGraphicsView* view){
	this->model = model;
	this->view = view;

	this->frontView = model.getFrontView();
	this->topView = model.getTopView();
	this->sideView = model.getSideView();
}

void twoDModelOutputTool::translateOrigin(){
	this->originShiftAmountFrontView = getMinCoordinates(frontView);
	this->originShiftAmountTopView = getMinCoordinates(topView);
	this->originShiftAmountSideView = getMinCoordinates(sideView);
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
	//drawing front view only
	Line* frontViewLines = frontView.getLines();
	for (int i = 0; i < frontView.getLineSize(); i++){
		Point p1 = frontViewLines -> getFirstPoint();
		Point p2 = frontViewLines -> getSecontPoint();

		view -> setp1((p1.getX() - originShiftAmountFrontView.getX())/scaleAmountFrontView, (p1.getY() - originShiftAmountFrontView.getY())/scaleAmountFrontView);
		view -> setp2((p2.getY() - originShiftAmountFrontView.getY())/scaleAmountFrontView, (p2.getY() - originShiftAmountFrontView.getY())/scaleAmountFrontView);

		view -> drawOutput2D();

		frontViewLines++;
	}
}
