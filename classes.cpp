#include <iostream>
#include <set>
#include <iterator>
 
using namespace std;
/** @defgroup group1 The First Group
 *  This is the first group
 *  @{
 */
/*! \class Point
A class to represent a point in space
*/
class Point{
	//! private floats are used to represent the coordinates
	float x; /*!< x coordinate */
	float y; /*!< y coordinate */
	float z; /*!< z coordinate */

public:
	//! Accessor function to get the x coordinate of point
	float getX(){
		return x;
	}
	//! Accessor function to get the y coordinate of point
	float getY(){
		return y;
	}
	//! Accessor function to get the z coordinate of point
	float getZ(){
		return z;
	}
  
  void setX(float x){
		this.x = x;
	}
	//! Accessor function to get the y coordinate of point
	void setY(float y){
		this.y = y;
	}
	//! Accessor function to get the z coordinate of point
	void setZ(float z){
		this.z = z;
	}
  
	//! Accessor function to get the array of coordinates of point
	float* getArrayCoors(){
		float ar[3];
		ar[0] = x;
		ar[1] = y;
		ar[2] = z;
		return ar;
	}
}

/*! \class Line 
A class to represent a line in space
*/
class Line{
	//! two private objects of class point are instantiated to represent the endpoints of line
	Point p1;

	Point p2;

public:
	//! Accessor function to get the first end point
	Point getFirstPoint(){
		return p1;
	}
	//! Accessor function to get the second end point
	Point getSecondPoint(){
		return p2;
	}
	//! Accessor function to get the array of end points
	Point* getArrayPoints(){
		Point ar[2] = {p1,p2};
		return ar;
	}
	
  void setFirstPoint(Point p1){
    this.p1 = p1;
  }
  
  void setSecondPoint(Point p2){
    this.p2 = p2;
  }
}

/*! \class Plane
A class to represent a plane in space
*/
class Plane{
	//! two private objects of class line are instantiated to represent the lines of plane
	Line l1;

	Line l2;

public:
	//! Accessor function to get the first line
	Line getFirstLine(){
		return l1;
	}
	//! Accessor function to get the second line
	Line getSecondLine(){
		return l2;
	}
	//! Accessor function to get array of lines
	Line* getArrayLines(){
		Line ar[2] = {l1,l2};
		return ar;
	}
  
  void setFirstLine(Line l1){
    this.l1 = l1;
  }
  
  void setSecondLine(Line l2){
    this.l2 = l2;
  }

}
/** @} */ // end of group1

/*! \class StartScreen
A class to represent a start screen
*/
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
}

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


}
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


}
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


}
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
}

/*! \class TwoDView
A class representing a single view of the orthographic projections
*/
class TwoDView{
	//! Private array of points and lines are instantiated 
	Point* points; /*< points represents the vertices */
	int pointSize = 0;
	Line* lines; /*< lines represents the edges */
	int lineSize = 0;

public:
	//! Accessor function to get the array of points
	Point* getPoints(){
		return points;
	}
	//! Accessor function to get the array of lines
	Line* getLines(){
		return lines;
	}
	void setPoints(Point* p){
		this.points = p;
	}

	void setLines(Line* l){
		this.lines = l;
	}

	int getPointSize(){
		return pointSize;
	}

	int getLineSize(){
		return lineSize;
	}

	void setPointSize(int s){
		this.pointSize += s;
	}

	void setLineSize(int s){
		this.lineSize += s;
	}


}

/*! \class TwoDModel
A class representing a 2D model containing the three views
*/
class TwoDModel{

	TwoDView frontView; /*< frontView is an object of TwoDView class */
	TwoDView topView; /*< topView is an object of TwoDView class */
	TwoDView sideView; /*< sideView is an object of TwoDView class */

public:
	//! Accessor function to get the front view
	TwoDView getFrontView(){
		return frontView;
	}
	//! Accessor function to get the top view
	TwoDView getTopView(){
		return topView;
	}	
	//! Accessor function to get the side view
	TwoDView getSideView(){
		return sideView;
	}

	void setFrontView(TwoDView v){
		this.frontView = v;
	}

	void setTopView(TwoDView v){
		this.topView = v;
	}

	void setSideView(TwoDView v){
		this.sideView = v;
	}



}

/*! \class ThreeDModel
A class representing a 3D model containing the vertices, edges and surfaces
*/
class ThreeDModel{

	Point* points; /*< points represent the vertices */ 
	int pointSize = 0;
	Line* lines; /*< lines represent the edges */
	int lineSize = 0;
	Planes* planes; /*< planes represent the surfaces */
	int planeSize = 0;

public:
	//! Accessor function to get the vertices
	Point* getPoints(){
		return points;
	}
	//! Accessor function to get the lines
	Line* getLines(){
		return lines;
	}
	//! Accessor function to get the surfaces
	Planes* getPlanes(){
		return planes;
	}

	void setPoints(Point* p){
		this.points = p;
	}

	void setLines(Line* l){
		this.lines = l;
	}

	void setPlanes(Plane* p){
		this.planes = p;
	}

	int getPointSize(){
		return pointSize;
	}

	int getLineSize(){
		return lineSize;
	}

	int getPlaneSize(){
		return planeSize;
	}

	void setPointSize(int s){
		this.pointSize += s;
	}

	void setLineSize(int s){
		this.lineSize += s;
	}

	void setPlaneSize(int s){
		this.planeSize += s;
	}

}
/** @} */ // end of group3

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
}

/*! \class ThreeDModelGenerator
A class responsible for generating the 3D model
*/
class ThreeDModelGenerator{

	TwoDModel model; /*< Every public function access this object representing the 2D model */

public:
	//! Input function to get the 2D model
	void getTwoDModel(){

	}
	//! This function returns a list of possible vertices in a array of point objects
	Point* PossibleVerticesConstructor(){

	}
	//! This function returns a list of possible edges in a array of line objects
	Line* PossibleEdgesConstructor(){

	}
	//! This function returns a list of possible surfaces in a array of plane objects
	Plane* PossibleSurfacesConstructor(){

	}
	//! This function checks if two given planes are duplicate or not 
	bool DuplicatePlaneChecker(Plane p1, Plane p2){

	}
	//! This function returns a list of possible closed loops in a array of plane objects
	Plane* PossibleClosedLoopFacesConstructor(){

	}
	//! This function returns a list of possible objects in a array of ThreeDModel objects
	ThreeDModel* PossibleObjectsConstructor(){

	}
	//! This function returns a ThreeDModel object after combining possible subobjects
	ThreeDModel PossibleObjectsCombiner(ThreeDModel *){

	}
	//! This function returns the final ThreeDModel object 
	ThreeDModel output(){

	}

}
/** @} */ // end of group4
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
}



