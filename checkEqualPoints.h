#ifndef CHECKEQUALPOINTS_H
#define CHECKEQUALPOINTS_H

bool checkEqualPoints(Point p1, Point p2){
	if(p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ()){
		return true;
	}
	return false;
}

#endif