#include "threeDModelOutputTool.h"
#include "../TwoDModelGenerator.h"

threeDModelOutputTool::threeDModelOutputTool(ThreeDModel model, threeDOutputWidget* view){
	this->model3D = model;
	this->view = view;
}

void threeDModelOutputTool::drawModel(){

	//rotate

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

	view -> show();
}