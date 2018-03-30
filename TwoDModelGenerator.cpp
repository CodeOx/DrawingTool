#include "TwoDModelGenerator.h"

TwoDModelGenerator::TwoDModelGenerator(ThreeDModel model){
    this->model = model;
}

Point TwoDModelGenerator::_3Dto2DPoint(Point p, string plane){
	Point _2DPoint = p;
    if(plane == "xy" || plane == "yx"){
      _2DPoint.setZ(0);
    }
    if(plane == "yz" || plane == "zy"){
      _2DPoint.setX(0);
    }
    if(plane == "zx" || plane == "xz"){
      _2DPoint.setY(0);
    }
    return _2DPoint;
}

Point* TwoDModelGenerator::_3Dto2DPoints(Point* pointArray, string plane, int arraySize){
	Point* _2DPointsArray = (Point*)malloc (arraySize * sizeof(Point));
	for (int i = 0; i < arraySize; i++){
  		Point _3DPoint = *pointArray;
  		Point _2DPoint = _3Dto2DPoint(_3DPoint, plane);
  		_2DPointsArray[i] = _2DPoint;
  		pointArray++;
	}
	return _2DPointsArray;
}

Line* TwoDModelGenerator::_3Dto2DLine(Line* lineArray, string plane, int arraySize){
	Line* _2DLineArray = (Line*)malloc (arraySize * sizeof(Line));
    for (int i = 0; i < arraySize; i++){
    	Line _3DLine = *lineArray;
		Point _3Dp1 = _3DLine.getFirstPoint();
		Point _3Dp2 = _3DLine.getSecondPoint();
		Point _2Dp1 = _3Dto2DPoint(_3Dp1, plane);
		Point _2Dp2 = _3Dto2DPoint(_3Dp2, plane);
		Line _2DLine;
		_2DLine.setFirstPoint(_2Dp1);
		_2DLine.setFirstPoint(_2Dp2);
		_2DLineArray[i] = _2DLine;
		lineArray++;
    }
    return _2DLineArray;
}

TwoDModel TwoDModelGenerator::output(){
	int pointSize = model.getPointSize();
	int lineSize = model.getLineSize();

	TwoDView xy;
	xy.setPoints(_3Dto2DPoints(model.getPoints(),"xy",pointSize));
	xy.setLines(_3Dto2DLine(model.getLines(),"xy",lineSize));
	xy.setPointSize(pointSize);
	xy.setLineSize(lineSize);

	TwoDView yz;
	yz.setPoints(_3Dto2DPoints(model.getPoints(),"yz",pointSize));
	yz.setLines(_3Dto2DLine(model.getLines(),"yz",lineSize));
	yz.setPointSize(pointSize);
	yz.setLineSize(lineSize);

	TwoDView zx;
	zx.setPoints(_3Dto2DPoints(model.getPoints(),"zx",pointSize));
	zx.setLines(_3Dto2DLine(model.getLines(),"zx",lineSize));
	zx.setPointSize(pointSize);
	zx.setLineSize(lineSize);

	TwoDModel output;
	output.setFrontView(xy);
	output.setTopView(yz);
	output.setSideView(zx);

	return output;
}
