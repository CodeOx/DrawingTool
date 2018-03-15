#include "ThreeDModelGenerator.h"


bool checkEqualPoints(Point p1, Point p2){
	if(p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ()){
		return true;
	}
	return false;
}

bool checkLineInView(Line l, TwoDView view){
	Line* lines;
	lines = view.getLines();
	for(int i = 0; i < view.getLineSize(); i++){
		Line viewLine = lines[i];
		if((checkEqualPoints(l.getFirstPoint(),viewLine.getFirstPoint()) && checkEqualPoints(l.getSecondPoint(),viewLine.getSecondPoint())) || (checkEqualPoints(l.getFirstPoint(),viewLine.getSecondPoint()) && checkEqualPoints(l.getSecondPoint(),viewLine.getFirstPoint()))){
			return true;
		}
		
	}
	return false;
}

bool checkLineInModel(Line l, TwoDModel model){
	TwoDView frontView = model.getFrontView();
	TwoDView topView = model.getTopView();
	TwoDView sideView = model.getSideView();
	return ((checkLineInView(l,frontView)) && (checkLineInView(l,sideView)) && (checkLineInView(l,topView)));
}
//! This function returns a list of possible edges in a LineList object
//PointList, LineList, PlaneList classes need to be defined
LineList ThreeDModelGenerator::PossibleEdgesConstructor(PointList points){
	int maxSize = points.getSize()*points.getSize();
	Line possibleEdges[maxSize];
	int linesForEachPoint[points.getSize()];
	for(int i = 0; i < points.getSize(); i++){
		linesForEachPoint[i] = 0;
	}
	Point* pointArray = points.getPoints();
	int lineCounter = 0;
	for(int i = 0; i < points.getSize(); i++){
		for(int j = i+1; j < points.getSize(); j++){
			Line temp;
			temp.setFirstPoint(pointArray[i]);
			temp.setSecondPoint(pointArray[j]);
			if(checkLineInModel(temp,model)){
				possibleEdges[i] = temp;
				linesForEachPoint[i] += 1;
				lineCounter += 1;
			}
		}
	}
	//get new list of points
	bool flag = true;
	Point newPoints[points.getSize()];
	int pointCounter = 0;
	for(int i = 0; i < points.getSize(); i++){
		if(linesForEachPoint[i] > 3){
			newPoints[pointCounter] = pointArray[i];
			pointCounter += 1;
		}
		else{
			flag = false;
		}
	}

	PointList p;
	p.setPoints(newPoints);
	p.setSize(pointCounter);

	if(flag){
		LineList ob;
		ob.setLines(possibleEdges);
		ob.setSize(lineCounter);
		return ob;
	}

	else{
		ThreeDModelGenerator::PossibleEdgesConstructor(p);
	}


}
