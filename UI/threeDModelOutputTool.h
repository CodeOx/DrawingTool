#ifndef THREEDMODELOUTPUTTOOL_H
#define THREEDMODELOUTPUTTOOL_H

#include "threeDOutputWidget.h"
#include "twoDModelOutputTool.h"
#include "../model.h"
#include <string>

class threeDModelOutputTool
{
	threeDOutputWidget* view;
	float finalScale = 400.0;
	ThreeDModel model3D;
	TwoDModel model2D;
	TwoDView frontView;
	Point originShiftAmountFrontView;
	float scaleAmountFrontView;
public:
	threeDModelOutputTool(ThreeDModel model, threeDOutputWidget* view);
	void drawModel();
	void rotate(std::string axis, float angle);
};

#endif