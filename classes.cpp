#include <iostream>
#include <set>
#include <iterator>
#include "ThreeDModelGenerator.h"
#include "TwoDModelGenerator.h" 

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