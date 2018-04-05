#include "ThreeDModelGenerator.h"
#include "debug.h"
#include <cstdlib>
#include <iostream>
#include <vector>

//frontView has z = 0, topView has x = 0
Point* combineFrontTop(Point* p1, Point* p2, int p1Size, int p2Size, int &combinedSize){
	std::vector<Point> combinedPoints;
	Point* p2_temp = p2;
	for(int i = 0; i < p1Size; i++){
		for(int j = 0; j < p2Size; j++){
			//std::cout<<"xxx"<<std::endl;
			//printPoint(*p1);
			//printPoint(*p2);
			if((*p1).getY() == (*p2).getY()){
				
				Point newPoint;
				newPoint.setX( (*p1).getX());
				newPoint.setY( (*p1).getY());
				newPoint.setZ ((*p2).getZ());
				combinedPoints.push_back(newPoint);
			}
		
			p2++;
		}
		p2 = p2_temp;
		p1++;
	}

	combinedSize = combinedPoints.size();
	Point* arrayCombinedPoints = (Point*)malloc (combinedSize*sizeof(Point));
	for(int i = 0; i < combinedSize ; i++){
		Point n = combinedPoints[i];
		arrayCombinedPoints[i] = combinedPoints[i];
	}
	return arrayCombinedPoints;
}

bool sideViewContainsCombined(Point p, TwoDView sideView){
	Point* sidePoints = sideView.getPoints();
	for(int i = 0 ; i < sideView.getPointSize(); i++){
		std::cout << "llll" << std::endl;
		printPoint(p);
		//printPoint(*sidePoints);
		if((*sidePoints).getX() == p.getX() && (*sidePoints).getZ() == p.getZ()){
			return true;
		}
		sidePoints++;
	}
	return false;
}

void ThreeDModelGenerator::PossibleVerticesConstructor(){
	
	TwoDView frontView = model.getFrontView();
	TwoDView topView = model.getTopView();
	TwoDView sideView = model.getSideView();

	std::vector<Point> threeDPoints;
	
	Point* frontPoints = frontView.getPoints();
	Point* topPoints = topView.getPoints();
	int combineFrontTopSize;
	Point* combinedFrontTop = combineFrontTop(frontPoints, topPoints, frontView.getPointSize(), topView.getPointSize(), combineFrontTopSize); 
	/*std::cout << "$$$$$$" << combineFrontTopSize << std::endl;
	for (int i = 0; i < combineFrontTopSize; i++){
		printPoint(combinedFrontTop[i]);
	}*/
	//remove duplicates
	int count = 0;
	for(int i = 0; i < combineFrontTopSize; i++){

		if(sideViewContainsCombined(combinedFrontTop[i], sideView)){
			//printPoint(*combinedFrontTop);
			threeDPoints.push_back(combinedFrontTop[i]);
			//printPoint(*combinedFrontTop);
			count++;
		}
	}

	std::cout << "hereeee" << std::endl;
	Point* arrayThreeDPoints = (Point*)malloc (count*sizeof(Point));
	for(int i = 0; i < count ; i++){
		arrayThreeDPoints[i] = threeDPoints[i];
		printPoint(threeDPoints[i]);
	}

	PointList temp;
	temp.setPoints(arrayThreeDPoints);
	temp.setSize(count);
	possibleVertices = temp;
}
