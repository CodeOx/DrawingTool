#include <iostream>
#include <set>
#include <iterator>
#include "ThreeDModelGenerator.h"
 
using namespace std;

class StartScreen
{
public:
	/*!
		Function to get the choice of 2D or 3D model input 
		from user
	*/
	char getChoice(){

	}
	//! Function to call GUI which gets input from user
	void callGUI(){

	}
	//! Constructor for this class
	StartScreen()
	//! Destructor for this class
	~StartScreen()
};

/** @defgroup group2 The Second Group
 *  This is the second group
 *  @{
 */
/*! \class DrawingTool
A class representing the drawing tools 
*/
class DrawingTool{

public:
	//! function which takes a model as input
	Model Input(){

	}

	DrawingTool()

	~DrawingTool()


};
/*! \class TwoDrawingTool
A class to take a 2D model as input, this class is derived from DrawingTool class 
*/
class TwoDrawingTool :: public DrawingTool{

	public:
	//! function which takes a 2D model as input
	TwoDModel Input(){

	}

	TwoDrawingTool()

	~TwoDrawingTool()


};
/*! \class ThreeDrawingTool
A class to take a 3D model as input, this class is derived from DrawingTool class 
*/
class ThreeDrawingTool :: public DrawingTool{

	public:
	//! function which takes a 3D model as input
	ThreeDModel Input(){

	}

	ThreeDrawingTool()

	~ThreeDrawingTool()


};
/** @} */ // end of group2

/** @defgroup group3 The Third Group
 *  This is the third group
 *  @{
 */
/*! \class Model
A class representing a general model
*/
class Model{
public:
	Model(){

	}
	~Model(){

	}
};

/** @defgroup group4 The Fourth Group
 *  This is the fourth group
 *  @{
 */
/*! \class TwoDModelGenerator
A class responsible for generating the 2D model
*/
class TwoDModelGenerator{

	ThreeDModel model; /*< Every public function access this object representing the 3D model */

public:
	//! Input function to get the 3D model
	TwoDModelGenerator(ThreeDModel model){
    this.model = model;
  }


	//plane can be xy,yz,zx
	Point _3Dto2DPoint(Point p, string plane){
		Point _3DPoint = new Point();
    _3DPoint.x = p.x;
    _3DPoint.y = p.y;
    _3DPoint.z = p.z;
    if(plane == "xy" || plane == "yx"){
      _3DPoint.z = 0;
    }
    if(plane == "yz" || plane == "zy"){
      _3DPoint.x = 0;
    }
    if(plane == "zx" || plane == "xz"){
      _3DPoint.y = 0;
    }
    return _3DPoint;
	}
	//return array of 2D points given array of 3D points and plane
	Point* _3Dto2DPoints(Point* pointArray, string plane, int arraySize){
		Point _2DPointsArray[arraySize];
		for (int i = 0; i < arraySize; i++){
      		Point _3DPoint = *pointArray;
      		Point _2DPoint = _3Dto2DPoint(_3DPoint, plane);
      		_2DPointsArray[i] = _2DPoint;
      		pointArray++;
    	}
    	return _2DPointsArray;
	}
	//return array of 2D lines given array of 3D lines and plane
	Line* _3Dto2DLine(Line* lineArray, string plane, int arraySize){
		Line _2DLineArray[arraySize];
    for (int i = 0; i < arraySize; i++){
      Line _3DLine = *lineArray;
      Point _3Dp1 = _3DLine.getFirstPoint();
      Point _3Dp2 = _3DLine.getSecondPoint();
      Point _2Dp1 = _3Dto2DPoint(_3Dp1, plane);
      Point _2Dp2 = _3Dto2DPoint(_3Dp2, plane);
      Line _2DLine;
      _2DLine.setFirstPoint(_2Dp1);
      _2DLine.setFirstPoint(_2Dp2);
      _2DLineArray[i] = _2DLine;
      lineArray++;
    }
    return _2DLineArray;
	}
	//! Output function returns a 2D model 
	TwoDmodel output(){
		int pointSize = model.getPointSize();
		int lineSize = model.getLineSize();

		TwoDView xy;
		xy.setPoints(_3Dto2DPoints(model.getPoints(),"xy",pointSize));
		xy.setLines(_3Dto2DPoints(model.getLines(),"xy",lineSize));

		TwoDView yz;
		xy.setPoints(_3Dto2DPoints(model.getPoints(),"yz",pointSize));
		xy.setLines(_3Dto2DPoints(model.getLines(),"yz",lineSize));

		TwoDView zx;
		xy.setPoints(_3Dto2DPoints(model.getPoints(),"zx",pointSize));
		xy.setLines(_3Dto2DPoints(model.getLines(),"zx",lineSize));

		TwoDModel output;
		output.setFrontView(xy);
		output.setTopView(yz);
		output.setSideView(zx);

		return output;
	}
};

/*! \class OutputTool
A class responsible for outputting the final output on the GUI
*/
class OutputTool{

public:
	TwoDmodel getTwoDModel(){

	}

	ThreeDModel getThreeDModel(){

	}

	void show2DOutput(){

	}

	void show3DOutput(){

	}
};