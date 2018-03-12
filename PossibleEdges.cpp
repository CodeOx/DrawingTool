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
Point* ThreeDModelGenerator::PossibleEdgesConstructor(PointList points){
	int maxSize = points.getSize()*points.getSize();
	Line possibleEdges[maxSize];
	Point pointArray[points.getSize()] = points.getPoints();
	int count = 0;
	for(int i = 0; i < points.getSize(); i++){
		for(int j = i+1; j < points.getSize(); j++){
			Line temp;
			temp.setFirstPoint(pointArray[i]);
			temp.setSecondPoint(pointArray[j]);
			if(checkLineInModel(temp,model)){
				possibleEdges[i] = temp;
				count += 1;
			}
		}
	}
	LineList ob;
	ob.setLines(possibleEdges);
	ob.setSize(count);
	return ob;
}
