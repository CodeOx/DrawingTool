#include "model.h"
#include <string>

#ifndef FILEPARSER_H
#define FILEPARSER_H

class FileParser{

public:
	ThreeDModel _3DModelInput(std::string filename);

	TwoDModel _2DModelInput(std::string filename);

	void parseFile(std::string filename, int choice);
};

#endif