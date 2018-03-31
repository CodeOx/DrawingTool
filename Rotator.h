#include "ThreeDModelGenerator.h"
#include <string>

#ifndef ROTATOR_H
#define ROTATOR_H

class Rotator{

	ThreeDModel model;

public:

	void setThreeDModel(ThreeDModel model);

	ThreeDModel rotate(ThreeDModel model, std::string axis, float angle);

	
};

#endif