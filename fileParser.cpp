#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "FileParser.h"
//----------the vector seems to malfunctioning--------------//
//--------Possible solution is to create iterator of vector,then store it in an array-------------//
ThreeDModel FileParser::_3DModelInput(std::string filename){
	std::ifstream infile;
	infile.open(filename);
	if(!infile){
		std::cout << "Unable to open file";
	}

	std::string line;
	bool pointsFlag = false;
	bool linesFlag = false;
	bool removeFlag = false;
	std::string points ("Points");
	std::string lines ("Lines");
	std::string remove ("Remove");
	ThreeDModel model;
	std::vector<Point> pointArray;
	std::vector<Line> lineArray;
	std::vector<Point> removePointArray;
	int removePointCounter = 0;
	int pointCounter = 0;
	int lineCounter = 0;

	while(std::getline(infile,line)){
		std::cout << "enter3" << line.substr(0,6) << "SEE" << std::endl;
		//std::cout << 
		if(points.compare(line.substr(0,6)) == 0){
			std::cout << "entering" << std::endl;
			removeFlag = false;
			linesFlag = false;
			pointsFlag = true;
		}
		
		if(lines.compare(line.substr(0,5)) == 0){
			removeFlag = false;
			linesFlag = true;
			pointsFlag = false;
		}

		if(remove.compare(line.substr(0,6)) == 0){
			removeFlag = true;
			linesFlag = false;
			pointsFlag = false;
		}

		std::istringstream iss(line);

		float x,y,z;
		float x1,y1,z1,x2,y2,z2;
		
		std::cout << "pointsFlag" << pointsFlag << std::endl;
		if(pointsFlag && iss >> x >> y >> z){
			std::cout << "final_enter" << std::endl;
			Point p;
			p.setX(x);
			p.setY(y);
			p.setZ(z);
			pointArray.push_back(p);
			pointCounter++;
		}

		if(linesFlag && iss >> x1 >> y1 >> z1 >> x2 >> y2 >> z2){

			Point firstPoint;
			Point secondPoint;
			Line line;
			//std::cout << "y1" << y1 << std::endl; 
			firstPoint.setX(x1);
			firstPoint.setY(y1);
			firstPoint.setZ(z1);
			secondPoint.setX(x2);
			secondPoint.setY(y2);
			secondPoint.setZ(z2);
			line.setFirstPoint(firstPoint);
			line.setSecondPoint(secondPoint);
			std::cout << lineCounter << std::endl;
			lineArray.push_back(line);
			lineCounter++;
			std::cout << "enter5" << std::endl;
		}

		if(removeFlag && iss >> x >> y >> z){
			Point p;
			p.setX(x);
			p.setY(y);
			p.setZ(z);
			removePointArray.push_back(p);
			removePointCounter++;

		}
		iss.clear();

	}
	//std::cout << "LOLLLL" << lineArray[0].getFirstPoint().getX() << std::endl;
	Point* newPointArray = (Point*)malloc (pointArray.size()*sizeof(Point));
	for(int i = 0; i < pointArray.size(); i++){
		newPointArray[i] = pointArray[i];
	}
	Line* newLineArray = (Line*)malloc (lineArray.size()*sizeof(Line));
	for(int i = 0; i < lineArray.size(); i++){
		newLineArray[i] = lineArray[i];
	}
	model.setPoints(newPointArray);
	model.setLines(newLineArray);
	std::cout << "pointCounter" << lineArray.size() << std::endl;
	model.setPointSize(pointArray.size());
	model.setLineSize(lineArray.size());
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
	std::vector<Point> frontPointArray;
	std::vector<Line> frontLineArray;
	std::vector<Point> topPointArray;
	std::vector<Line> topLineArray;
	std::vector<Point> sidePointArray;
	std::vector<Line> sideLineArray;
	int frontPointCounter = 0;
	int frontLineCounter = 0;
	int topPointCounter = 0;
	int topLineCounter = 0;
	int sidePointCounter = 0;
	int sideLineCounter = 0;

	while(std::getline(infile,line)){

		if(points.compare(line.substr(0,6)) == 0){
			linesFlag = false;
			pointsFlag = true;
		}
		
		if(lines.compare(line.substr(0,5)) == 0){
			linesFlag = true;
			pointsFlag = false;
		}

		if(frontViewString.compare(line.substr(0,9)) == 0){
			front = true;
			top = false;
			side = false;
		}

		if(topViewString.compare(line.substr(0,7)) == 0){
			front = false;
			top = true;
			side = false;
		}

		if(sideViewString.compare(line.substr(0,8)) == 0){
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
			frontPointArray.push_back(p);
			frontPointCounter++;
		}

		if(pointsFlag && top && iss >> x >> y >> z){
			Point p;
			p.setX(x);
			p.setY(y);
			p.setZ(z);
			topPointArray.push_back(p);
			topPointCounter++;
		}

		if(pointsFlag && side && iss >> x >> y >> z){
			Point p;
			p.setX(x);
			p.setY(y);
			p.setZ(z);
			sidePointArray.push_back(p);
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
			frontLineArray.push_back(line);
			frontLineCounter++;
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
			topLineArray.push_back(line);
			topLineCounter++;
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
			sideLineArray.push_back(line);
			sideLineCounter++;
		}

		iss.clear();

	}

	Point* newFrontPointArray = (Point*)malloc (frontPointArray.size()*sizeof(Point));
	Line* newFrontLineArray = (Line*)malloc (frontLineArray.size()*sizeof(Line));

	for(int i = 0; i < frontPointArray.size(); i++){
		newFrontPointArray[i] = frontPointArray[i];
	}
	for(int i = 0; i < frontLineArray.size(); i++){
		newFrontLineArray[i] = frontLineArray[i];
	}

	frontView.setPoints(newFrontPointArray);
	frontView.setLines(newFrontLineArray);
	frontView.setPointSize(frontPointCounter);
	frontView.setLineSize(frontLineCounter);

	Point* newSidePointArray = (Point*)malloc (sidePointArray.size()*sizeof(Point));
	Line* newSideLineArray = (Line*)malloc (sideLineArray.size()*sizeof(Line));

	for(int i = 0; i < sidePointArray.size(); i++){
		newSidePointArray[i] = sidePointArray[i];
	}
	for(int i = 0; i < sideLineArray.size(); i++){
		newSideLineArray[i] = sideLineArray[i];
	}

	sideView.setPoints(newSidePointArray);
	sideView.setLines(newSideLineArray);
	sideView.setPointSize(sidePointCounter);
	sideView.setLineSize(sideLineCounter);

	Point* newTopPointArray = (Point*)malloc (topPointArray.size()*sizeof(Point));
	Line* newTopLineArray = (Line*)malloc (topLineArray.size()*sizeof(Line));

	for(int i = 0; i < topPointArray.size(); i++){
		newTopPointArray[i] = topPointArray[i];
	}
	for(int i = 0; i < topLineArray.size(); i++){
		newTopLineArray[i] = topLineArray[i];
	}

	topView.setPoints(newTopPointArray);
	topView.setLines(newTopLineArray);
	topView.setPointSize(topPointCounter);
	topView.setLineSize(topLineCounter);

	model.setFrontView(frontView);
	model.setTopView(topView);
	model.setSideView(sideView);


	infile.close();
	return model;
}

PointList FileParser::getRemovePoints(std::string filename){
	std::ifstream infile;
	infile.open(filename);
	if(!infile){
		std::cout << "Unable to open file";
	}
	std::string line;
	bool read = false;
	std::string remove ("Remove");
	PointList points;
	std::vector<Point> pointArray;
	int pointCounter = 0;
	while(std::getline(infile,line)){
		if(remove.compare(line.substr(0,6)) == 0){
			read = true;
		}
		std::istringstream iss(line);

		float x,y,z;

		if(read && iss >> x >> y >> z){
			Point p;
			p.setX(x);
			p.setY(y);
			p.setZ(z);
			pointArray.push_back(p);
			pointCounter++;
		}
	}
	Point* newPointArray = (Point*)malloc (pointArray.size()*sizeof(Point));
	for(int i = 0; i < pointArray.size(); i++){
		newPointArray[i] = pointArray[i];
	}
	
	points.setPoints(newPointArray);
	points.setSize(pointCounter);

	return points;
}

void FileParser::parseFile(std::string filename, int choice){
	
	if(choice == 1){
		_2DModelInput(filename);
	}
	else{
		_3DModelInput(filename);
	}
}
