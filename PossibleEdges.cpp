#include "ThreeDModelGenerator.h"

bool checkLineInView(Line l, TwoDView view){
	Line lines[view.getLineSize()] = view.getLines();
	for(int i = 0; i < view.getLineSize(); i++){
		Line viewLine = lines[i];
		if((l.getFirstPoint() == viewLine.getFirstPoint() && l.getSecondPoint() == viewLine.getSecondPoint()) || (l.getFirstPoint() == viewLine.getSecondPoint() && l.getSecondPoint() == viewLine.getFirstPoint())){
			return true;
		}
		
	}
	return false;
}
bool checkLineInModel(Line l, TwoDModel model){
	frontView = model.getFrontView();
	topView = model.getTopView();
	sideView = model.getSideView();
	return ((checkLineInView(l,frontView)) && (checkLineInView(l,sideView)) && (checkLineInView(l,topView)))
}
//! This function returns a list of possible edges in a LineList object
//PointList, LineList, PlaneList classes need to be defined
LineList ThreeDModelGenerator::PossibleEdgesConstructor(PointList points){
	int maxSize = points.getSize()*points.getSize();
	Line possibleEdges[maxSize];
	int linesForEachPoint[points.getSize()] = {0};
	Point pointArray[points.getSize()] = points.getPoints();
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
	flag = true;
	Point newPoints[points.getSize()];
	pointCounter = 0;
	for(int i = 0; i < points.getSize(); i++){
		if(linesForEachPoint[i] > 3){
			newPoints[pointCounter] = linesForEachPoint[i];
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
