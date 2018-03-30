#ifndef TWODMODELOUTPUTTOOL_H
#define TWODMODELOUTPUTTOOL_H

#include "myqgraphicsview.h"
#include "../model.h"

class twoDModelOutputTool
{
	MyQGraphicsView* view;
	float finalScale = 400.0;
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
	void translateOrigin();
	void normalise();
public:
	twoDModelOutputTool(TwoDModel model, MyQGraphicsView* view);
	void drawModel();
};

#endif