class PointList{
	Point* points;
	int size;

public:
	void getPoints(){
		return points;
	}

	void getSize(){
		return size;
	}

	void setPoints(Point* points){
		this->points = points;
	}

	void setSize(int size){
		this->size = size;
	}
}

class LineList{
	line* lines;
	int size;

public:
	void getlines(){
		return lines;
	}

	void getSize(){
		return size;
	}

	void setlines(line* lines){
		this->lines = lines;
	}

	void setSize(int size){
		this->size = size;
	}
}

class planeList{
	plane* planes;
	int size;

public:
	void getplanes(){
		return planes;
	}

	void getSize(){
		return size;
	}

	void setplanes(plane* planes){
		this->planes = planes;
	}

	void setSize(int size){
		this->size = size;
	}
}