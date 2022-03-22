#pragma once
#include "Point.h"

class Manipulator : public Point
{

private:

	double radius;
	

public:

	Manipulator() : Point()
	{}

	Manipulator(double _x, double _y) : Point(_x,_y)
	{}

	double getRadius();	
	void setRadius(double cRadius);
	bool proverkaEntry(double cX, double cY);
	void entry_x_y_r();
	




};

