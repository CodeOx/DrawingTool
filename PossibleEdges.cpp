#include "ThreeDModelGenerator.h"
#include "checkEqualPoints.h"
#include "debug.h"
#include <iostream>

bool checkLineInFrontView(Line l, TwoDView view){
	Line* lines;
	Line newLine;
	lines = view.getLines();
	Point p1 = l.getFirstPoint();
	Point p2 = l.getSecondPoint();
	p1.setZ(0);
	p2.setZ(0);
	newLine.setFirstPoint(p1);
	newLine.setSecondPoint(p2);
	for(int i = 0; i < view.getLineSize(); i++){
		Line viewLine = lines[i];
		//std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<std::endl;
		//printLine(newLine);
		//printLine(lines[i]);
		if((checkEqualPoints(newLine.getFirstPoint(),viewLine.getFirstPoint()) && checkEqualPoints(newLine.getSecondPoint(),viewLine.getSecondPoint())) || (checkEqualPoints(newLine.getFirstPoint(),viewLine.getSecondPoint()) && checkEqualPoints(newLine.getSecondPoint(),viewLine.getFirstPoint()))){
			return true;
		}
		
	}
	return false;
}

bool checkLineInTopView(Line l, TwoDView view){
	Line* lines;
	Line newLine;
	lines = view.getLines();
	Point p1 = l.getFirstPoint();
	Point p2 = l.getSecondPoint();
	p1.setX(0);
	p2.setX(0);
	newLine.setFirstPoint(p1);
	newLine.setSecondPoint(p2);
	for(int i = 0; i < view.getLineSize(); i++){
		Line viewLine = lines[i];
		//std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<std::endl;
		//printLine(newLine);
		//printLine(lines[i]);
		if((checkEqualPoints(newLine.getFirstPoint(),viewLine.getFirstPoint()) && checkEqualPoints(newLine.getSecondPoint(),viewLine.getSecondPoint())) || (checkEqualPoints(newLine.getFirstPoint(),viewLine.getSecondPoint()) && checkEqualPoints(newLine.getSecondPoint(),viewLine.getFirstPoint()))){
			return true;
		}
		
	}
	return false;
}

bool checkLineInSideView(Line l, TwoDView view){
	Line* lines;
	Line newLine;
	lines = view.getLines();
	Point p1 = l.getFirstPoint();
	Point p2 = l.getSecondPoint();
	p1.setY(0);
	p2.setY(0);
	newLine.setFirstPoint(p1);
	newLine.setSecondPoint(p2);
	for(int i = 0; i < view.getLineSize(); i++){
		Line viewLine = lines[i];
		//std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<std::endl;
		//printLine(newLine);
		//printLine(lines[i]);
		if((checkEqualPoints(newLine.getFirstPoint(),viewLine.getFirstPoint()) && checkEqualPoints(newLine.getSecondPoint(),viewLine.getSecondPoint())) || (checkEqualPoints(newLine.getFirstPoint(),viewLine.getSecondPoint()) && checkEqualPoints(newLine.getSecondPoint(),viewLine.getFirstPoint()))){
			return true;
		}
		
	}
	return false;
}

bool checkLineInModel(Line l, TwoDModel model){
	TwoDView frontView = model.getFrontView();
	TwoDView topView = model.getTopView();
	TwoDView sideView = model.getSideView();
	return ((checkLineInFrontView(l,frontView)) || (checkLineInSideView(l,sideView)) || (checkLineInTopView(l,topView)));
}
//! This function returns a list of possible edges in a LineList object
//PointList, LineList, PlaneList classes need to be defined
void ThreeDModelGenerator::PossibleEdgesConstructor(){
	PointList points = possibleVertices;
	//std::cout<<"here"<< possibleVertices.getSize()<<"hiii"<<std::endl;
	int maxSize = points.getSize()*points.getSize();
	Line* possibleEdgesTemp = (Line*)malloc (maxSize*sizeof(Line));
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
			//std::cout<<"**********"<<std::endl;
			//printLine(temp);
			if(checkLineInModel(temp,model)){
				//std::cout<<"here?"<<std::endl;
				possibleEdgesTemp[lineCounter] = temp;
				linesForEachPoint[i] += 1;
				linesForEachPoint[j] += 1;
				lineCounter += 1;
			}
		}
	}
	//get new list of points
	bool flag = true;
	Point* newPoints = (Point*)malloc ((points.getSize())*sizeof(Point));
	int pointCounter = 0;
	for(int i = 0; i < points.getSize(); i++){

		//std::cout << std::endl << linesForEachPoint[i] << "\t" << std::endl;
		//printPoint( points.getPoints()[i]);

		if(linesForEachPoint[i] >= 3){
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

	possibleVertices = p;

	if(flag){
		LineList ob;
		ob.setLines(possibleEdgesTemp);
		ob.setSize(lineCounter);
		/*for (int i = 0; i < lineCounter; i++){
			std::cout<<"aaaaaaa"<<std::endl;
			printLine(possibleEdgesTemp[i]);
		}*/
		possibleEdges = ob;
		//std::cout <<"fvagbagbadgbabvbgab" << possibleEdges.getSize() << std::endl;
	}

	else{
		ThreeDModelGenerator::PossibleEdgesConstructor();
	}


}
