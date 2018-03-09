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

	}
	//! Accessor function to get the y coordinate of point
	float getY(){

	}
	//! Accessor function to get the z coordinate of point
	float getZ(){

	}
	//! Accessor function to get the array of coordinates of point
	float* getArrayCoors(){

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

	}
	//! Accessor function to get the second end point
	Point getSecondPoint(){

	}
	//! Accessor function to get the array of end points
	Point* getArrayPoints(){

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

	}
	//! Accessor function to get the second line
	Line getSecondLine(){

	}
	//! Accessor function to get array of lines
	Line* getArrayLines(){

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

	Line* lines; /*< lines represents the edges */

public:
	//! Accessor function to get the array of points
	Point* getPoints(){

	}
	//! Accessor function to get the array of lines
	Line* getLines(){

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

	}
	//! Accessor function to get the top view
	TwoDView getTopView(){

	}	
	//! Accessor function to get the side view
	TwoDView getSideView(){

	}


}

/*! \class ThreeDModel
A class representing a 3D model containing the vertices, edges and surfaces
*/
class ThreeDModel{

	Point* points; /*< points represent the vertices */ 

	Line* lines; /*< lines represent the edges */

	Planes* planes; /*< planes represent the surfaces */

public:
	//! Accessor function to get the vertices
	Point* getPoints(){

	}
	//! Accessor function to get the lines
	Line* getLines(){

	}
	//! Accessor function to get the surfaces
	Planes* getSurfaces(){

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
	void getThreeDModel(){

	}
	//! Rotator function takes 3D model and returns the rotated 3D model
	ThreeDModel rotator(){

	}
	//! Output function returns a 2D model 
	TwoDmodel output(){

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



