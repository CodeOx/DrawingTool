#include "ThreeDModelGenerator.h"
#include <vector>

//frontView has z = 0, topView has x = 0
Point* combineFrontTop(Point* p1, Point* p2, int p1Size, int p2Size, int &combinedSize){
	std::vector<Point> combinedPoints;

	for(int i = 0; i < p1Size; i++){

		for(int j = 0; j < p2Size; j++){
		
			if((*p1).getY() == (*p2).getY()){
				
				Point newPoint;
				newPoint.setX( (*p1).getX());
				newPoint.setY( (*p1).getY());
				newPoint.setZ ((*p2).getZ());

				combinedPoints.push_back(newPoint);
			}
		
			p2++;
		}
		
		p1++;
	}

	combinedSize = combinedPoints.size();

	Point* arrayCombinedPoints = &combinedPoints[0];
	return arrayCombinedPoints;
}

bool sideViewContainsCombined(Point p, TwoDView sideView){
	Point* sidePoints = sideView.getPoints();
	for(int i = 0 ; i < sideView.getPointSize(); i++){
		if((*sidePoints).getX() == p.getX() && (*sidePoints).getZ() == p.getZ()){
			return true;
		}
		sidePoints++;
	}
}

PointList ThreeDModelGenerator::PossibleVerticesConstructor(){
	TwoDView frontView = model.getFrontView();
	TwoDView topView = model.getTopView();
	TwoDView sideView = model.getSideView();

	std::vector<Point> threeDPoints;
	
	Point* frontPoints = frontView.getPoints();
	Point* topPoints = topView.getPoints();

	int combineFrontTopSize;
	Point* combinedFrontTop = combineFrontTop(frontPoints, topPoints, frontView.getPointSize(), topView.getPointSize(), combineFrontTopSize); 

	for(int i = 0; i < combineFrontTopSize; i++){
		if(sideViewContainsCombined(*combinedFrontTop, sideView)){
			threeDPoints.push_back(*combinedFrontTop);
		}
	}

	Point* arrayThreeDPoints = &threeDPoints[0];
	PointList p;
	p.setPoints(arrayThreeDPoints);
	p.setSize(threeDPoints.size());
	return p;
}