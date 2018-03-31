#include <iostream>
#include <fstream>
#include<sstream>
#include <string>
#include <vector>
#include "FileParser.h"

ThreeDModel FileParser::_3DModelInput(std::string filename){
	std::ifstream infile;
	infile.open(filename);
	if(!infile){
		std::cout << "Unable to open file";
	}
	std::string line;
	bool pointsFlag = false;
	bool linesFlag = false;
	std::string points ("Points");
	std::string lines ("Lines");
	std::string frontView ("FrontView");
	std::string sideView ("SideView");
	std::string topView ("TopView");
	ThreeDModel model;
	Point* pointArray;
	Line* lineArray;
	int pointCounter = 0;
	int lineCounter = 0;

	while(std::getline(infile,line)){
		if(line.compare(points)!= 0){
			linesFlag = false;
			pointsFlag = true;
		}
		
		if(line.compare(lines) != 0){
			linesFlag = true;
			pointsFlag = false;
		}

		std::istringstream iss(line);

		float x,y,z;
		float x1,y1,z1,x2,y2,z2;

		if(pointsFlag && iss >> x >> y >> z){
			Point p;
			p.setX(x);
			p.setY(y);
			p.setZ(z);
			pointArray[pointCounter] = p;
			pointCounter++;
		}

		if(linesFlag && iss >> x1 >> y1 >> z1 >> x2 >> y2 >> z2){
			Point firstPoint;
			Point secondPoint;
			Line line;
			firstPoint.setX(x1);
			firstPoint.setY(y1);
			firstPoint.setZ(z1);
			secondPoint.setX(x2);
			secondPoint.setY(y2);
			secondPoint.setZ(z2);
			line.setFirstPoint(firstPoint);
			line.setSecondPoint(secondPoint);
			lineArray[lineCounter] = line;
		}
		//iss.close();

	}
	model.setPoints(pointArray);
	model.setLines(lineArray);
	model.setPointSize(pointCounter);
	model.setLineSize(lineCounter);
	infile.close();
	return model;
}

TwoDModel FileParser::_2DModelInput(std::string filename){
	std::ifstream infile;
	infile.open(filename);
	if(!infile){
		std::cout << "Unable to open file";
	}
	std::string line;
	bool pointsFlag = false;
	bool linesFlag = false;
	bool front = false;
	bool top = false;
	bool side = false;
	std::string points ("Points");
	std::string lines ("Lines");
	std::string frontViewString ("FrontView");
	std::string sideViewString ("SideView");
	std::string topViewString ("TopView");
	TwoDModel model;
	TwoDView frontView;
	TwoDView topView;
	TwoDView sideView;
	Point* frontPointArray;
	Line* frontLineArray;
	Point* topPointArray;
	Line* topLineArray;
	Point* sidePointArray;
	Line* sideLineArray;
	int frontPointCounter = 0;
	int frontLineCounter = 0;
	int topPointCounter = 0;
	int topLineCounter = 0;
	int sidePointCounter = 0;
	int sideLineCounter = 0;

	while(std::getline(infile,line)){

		if(line.compare(points) != 0){
			linesFlag = false;
			pointsFlag = true;
		}
		
		if(line.compare(lines) != 0){
			linesFlag = true;
			pointsFlag = false;
		}

		if(line.compare(frontViewString)){
			front = true;
			top = false;
			side = false;
		}

		if(line.compare(topViewString)){
			front = false;
			top = true;
			side = false;
		}

		if(line.compare(sideViewString)){
			front = false;
			top = false;
			side = true;
		}

		std::istringstream iss(line);

		float x,y,z;
		float x1,y1,z1,x2,y2,z2;
		
		if(pointsFlag && front && iss >> x >> y >> z){
			Point p;
			p.setX(x);
			p.setY(y);
			p.setZ(z);
			frontPointArray[frontPointCounter] = p;
			frontPointCounter++;
		}

		if(pointsFlag && top && iss >> x >> y >> z){
			Point p;
			p.setX(x);
			p.setY(y);
			p.setZ(z);
			topPointArray[topPointCounter] = p;
			topPointCounter++;
		}

		if(pointsFlag && side && iss >> x >> y >> z){
			Point p;
			p.setX(x);
			p.setY(y);
			p.setZ(z);
			sidePointArray[sidePointCounter] = p;
			sidePointCounter++;
		}

		if(linesFlag && front && iss >> x1 >> y1 >> z1 >> x2 >> y2 >> z2){
			Point firstPoint;
			Point secondPoint;
			Line line;
			firstPoint.setX(x1);
			firstPoint.setY(y1);
			firstPoint.setZ(z1);
			secondPoint.setX(x2);
			secondPoint.setY(y2);
			secondPoint.setZ(z2);
			line.setFirstPoint(firstPoint);
			line.setSecondPoint(secondPoint);
			frontLineArray[frontLineCounter] = line;
		}

		if(linesFlag && top && iss >> x1 >> y1 >> z1 >> x2 >> y2 >> z2){
			Point firstPoint;
			Point secondPoint;
			Line line;
			firstPoint.setX(x1);
			firstPoint.setY(y1);
			firstPoint.setZ(z1);
			secondPoint.setX(x2);
			secondPoint.setY(y2);
			secondPoint.setZ(z2);
			line.setFirstPoint(firstPoint);
			line.setSecondPoint(secondPoint);
			topLineArray[topLineCounter] = line;
		}

		if(linesFlag && side && iss >> x1 >> y1 >> z1 >> x2 >> y2 >> z2){
			Point firstPoint;
			Point secondPoint;
			Line line;
			firstPoint.setX(x1);
			firstPoint.setY(y1);
			firstPoint.setZ(z1);
			secondPoint.setX(x2);
			secondPoint.setY(y2);
			secondPoint.setZ(z2);
			line.setFirstPoint(firstPoint);
			line.setSecondPoint(secondPoint);
			sideLineArray[sideLineCounter] = line;
		}

		//iss.close();

	}

	frontView.setPoints(frontPointArray);
	frontView.setLines(frontLineArray);
	frontView.setPointSize(frontPointCounter);
	frontView.setLineSize(frontLineCounter);

	sideView.setPoints(sidePointArray);
	sideView.setLines(sideLineArray);
	sideView.setPointSize(sidePointCounter);
	sideView.setLineSize(sideLineCounter);

	topView.setPoints(topPointArray);
	topView.setLines(topLineArray);
	topView.setPointSize(topPointCounter);
	topView.setLineSize(topLineCounter);

	model.setFrontView(frontView);
	model.setTopView(topView);
	model.setSideView(sideView);


	infile.close();
	return model;
}

void FileParser::parseFile(std::string filename, int choice){
	if(choice == 1){
		_2DModelInput(filename);
	}
	else{
		_3DModelInput(filename);
	}
}
