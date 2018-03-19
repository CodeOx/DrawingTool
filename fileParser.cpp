#include <fstream>
#include <string>
#include <vector>
#include "model.h"

void fileParser(string filename, int choice){
	if(choice == 1){
		_2DModelInput(filename);
	}
	else{
		_3DModelInput(filename);
	}
}

ThreeDModel _3DModelInput(string filename){
	ifstream infile;
	infile.open(filename);
	if(!infile){
		cout << "Unable to open file";
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
			lineFlags = false;
			pointsFlag = true;
		}
		
		if(line.compare(lines) != 0){
			linesFlag = true;
			pointsFlag = false;
		}

		std::isstringstream iss(line);

		int x,y,z;
		
		if(pointsFlag && line >> x >> y >> z){
			Point p;
			p.setX(x);
			p.setY(y);
			p.setZ(z);
			pointArray[pointCounter] = p;
			pointCounter++;
		}

		if(linesFlag && line >> x1 >> y1 >> z1 >> x2 >> y2 >> z2){
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
		iss.close();

	}
	model.setPoints(pointArray);
	model.setLines(lineArray);
	model.setPointSize(pointCounter);
	model.setLineSize(lineCounter);
	infile.close();
	return model;
}

TwoDModel _2DModelInput(string filename){
	ifstream infile;
	infile.open(filename);
	if(!infile){
		cout << "Unable to open file";
	}
	std::string line;
	bool pointsFlag = false;
	bool linesFlag = false;
	bool front = false;
	bool top = false;
	bool side = false;
	std::string points ("Points");
	std::string lines ("Lines");
	std::string frontView ("FrontView");
	std::string sideView ("SideView");
	std::string topView ("TopView");
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
			lineFlags = false;
			pointsFlag = true;
		}
		
		if(line.compare(lines) != 0){
			linesFlag = true;
			pointsFlag = false;
		}

		if(line.compare(frontView)){
			front = true;
			top = false;
			side = false;
		}

		if(line.compare(topView)){
			front = false;
			top = true;
			side = false;
		}

		if(line.compare(sideView)){
			front = false;
			top = false;
			side = true;
		}

		std::isstringstream iss(line);

		int x,y,z;
		
		if(pointsFlag && front && line >> x >> y >> z){
			Point p;
			p.setX(x);
			p.setY(y);
			p.setZ(z);
			frontPointArray[frontPointCounter] = p;
			frontPointCounter++;
		}

		if(pointsFlag && top && line >> x >> y >> z){
			Point p;
			p.setX(x);
			p.setY(y);
			p.setZ(z);
			topPointArray[topPointCounter] = p;
			topPointCounter++;
		}

		if(pointsFlag && side && line >> x >> y >> z){
			Point p;
			p.setX(x);
			p.setY(y);
			p.setZ(z);
			sidePointArray[pointCounter] = p;
			sidePointCounter++;
		}

		if(linesFlag && front && line >> x1 >> y1 >> z1 >> x2 >> y2 >> z2){
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

		if(linesFlag && top && line >> x1 >> y1 >> z1 >> x2 >> y2 >> z2){
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

		if(linesFlag && side && line >> x1 >> y1 >> z1 >> x2 >> y2 >> z2){
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

		iss.close();

	}

	frontView.setPoints(frontPointArray);
	frontView.setLines(frontLineArray);
	frontView.setPointSize(frontPointCounter);
	frontView.setLineSize(frontlineCounter);

	sideView.setPoints(sidePointArray);
	sideView.setLines(sideLineArray);
	sideView.setPointSize(sidePointCounter);
	sideView.setLineSize(sidelineCounter);

	topView.setPoints(topPointArray);
	topView.setLines(topLineArray);
	topView.setPointSize(topPointCounter);
	topView.setLineSize(toplineCounter);

	model.setFrontView(frontView);
	model.setTopView(topView);
	model.setSideView(SideView);


	infile.close();
	return model;




