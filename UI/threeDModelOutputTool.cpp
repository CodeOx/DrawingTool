#include "threeDModelOutputTool.h"
#include "../TwoDModelGenerator.h"
#include "../Rotator.h"

threeDModelOutputTool::threeDModelOutputTool(ThreeDModel model, threeDOutputWidget* view){
	this->model3D = model;
	this->view = view;
}

void threeDModelOutputTool::rotate(std::string axis, float angle){
	Rotator r;
	r.setThreeDModel(model3D);
	model3D = r.rotate(model3D, axis ,angle);
	view -> reset();
	view -> items().clear();
	view -> viewport()->update();
	drawModel();
}

void threeDModelOutputTool::drawModel(){

	if (initialFlag){
		//rotate
		Rotator r;
		r.setThreeDModel(model3D);
		model3D = r.rotate(model3D, "x",45.0);
		model3D = r.rotate(model3D, "z",45.0);

		initialFlag = false;
	}

	//generate 2d model
	TwoDModelGenerator twoDgenerator(model3D);
	model2D = twoDgenerator.output();
	TwoDView frontView = model2D.getFrontView();

	//get scale and shift amounts
	twoDModelOutputTool outputTool2D(model2D);
	outputTool2D.translateOrigin();
	outputTool2D.normalise();
	Point originShiftAmountFrontView = outputTool2D.getOriginShiftAmountFrontView();
	float scaleAmountFrontView = outputTool2D.getScaleAmountFrontView() * (finalScale/outputTool2D.getFinalScale());

	//drawing front view
	Line* frontViewLines = frontView.getLines();
	for (int i = 0; i < frontView.getLineSize(); i++){
		Point p1 = frontViewLines -> getFirstPoint();
		Point p2 = frontViewLines -> getSecondPoint();

		float p1NormalisedX = ((p1.getX() - originShiftAmountFrontView.getX())*scaleAmountFrontView) + 50.0;
		float p1NormalisedY = ((p1.getY() - originShiftAmountFrontView.getY())*scaleAmountFrontView) + 50.0;
		float p2NormalisedX = ((p2.getX() - originShiftAmountFrontView.getX())*scaleAmountFrontView) + 50.0;
		float p2NormalisedY = ((p2.getY() - originShiftAmountFrontView.getY())*scaleAmountFrontView) + 50.0;

		view -> setp1(p1NormalisedX, p1NormalisedY);
		view -> setp2(p2NormalisedX, p2NormalisedY);

		view -> drawOutput2D();

		frontViewLines++;
	}
}