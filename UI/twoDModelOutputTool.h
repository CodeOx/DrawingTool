#ifndef TWODMODELOUTPUTTOOL_H
#define TWODMODELOUTPUTTOOL_H

#include "myqgraphicsview.h"
#include "../model.h"

class twoDModelOutputTool
{
	MyQGraphicsView* view;
	float finalScale = 200.0;
	TwoDModel model;
	TwoDView frontView;
	TwoDView topView;
	TwoDView sideView;
	Point originShiftAmountFrontView;
	Point originShiftAmountTopView;
	Point originShiftAmountSideView;
	float scaleAmountFrontView;
	float scaleAmountTopView;
	float scaleAmountSideView;
public:
	void translateOrigin();
	void normalise();
	twoDModelOutputTool(TwoDModel model);
	twoDModelOutputTool(TwoDModel model, MyQGraphicsView* view);
	Point getOriginShiftAmountFrontView();
	float getScaleAmountFrontView();
	float getFinalScale();
	void drawModel();
};

#endif