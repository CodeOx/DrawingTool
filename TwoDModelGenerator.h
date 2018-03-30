#include "model.h"
#include <string>

using namespace std;

/*! \class TwoDModelGenerator
A class responsible for generating the 2D model
*/

class TwoDModelGenerator{

	ThreeDModel model; /*< Every public function access this object representing the 3D model */

public:
	//! Input function to get the 3D model
	TwoDModelGenerator(ThreeDModel model);
	//plane can be xy,yz,zx
	Point _3Dto2DPoint(Point p, string plane);
	//return array of 2D points given array of 3D points and plane
	Point* _3Dto2DPoints(Point* pointArray, string plane, int arraySize);
	//return array of 2D lines given array of 3D lines and plane
	Line* _3Dto2DLine(Line* lineArray, string plane, int arraySize);
	//! Output function returns a 2D model 
	TwoDModel output();
};