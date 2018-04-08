#include "model.h"
#include "Lists.h"
#include <string>

#ifndef FILEPARSER_H
#define FILEPARSER_H

/*! \class FileParser
A class representing a file parser  
*/
class FileParser{

public:
	//! function which takes a 3D model as input
	ThreeDModel _3DModelInput(std::string filename);
	//! function which takes a 2D model as input
	TwoDModel _2DModelInput(std::string filename);

	PointList getRemovePoints(std::string filename);

	void parseFile(std::string filename, int choice);
};

#endif
