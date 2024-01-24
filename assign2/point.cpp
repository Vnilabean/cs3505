#include "point.h"
#include <iostream>
/*
Point class for CS 3505 lecture 3.
A Point holds x and y values.
By Eric Heisler and STUDENT_NAME
*/

// Implement the methods prototyped in point.h
// You can include comments here if desired, 
// but they are already documented in point.h

Point::Point() {}

Point::Point(double initx, double inity) : x(initx), y(inity) {}

Point::~Point() {}

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

// Operators
Point Point::operator*(double scaleFactor) {
	Point res(x*scaleFactor, y*scaleFactor);
	return res;
}

// This doesn't start with Point:: so it is not class code.
std::ostream& operator<<(std::ostream& output, Point pt) {
    output << pt.x << ", " << pt.y;
    return output;
}

// Implementation the friend operation for *=
Point& operator*=(Point& pt, Transform tr) {
    // Get the values for the point
    double x = pt.getX();
    double y = pt.getY();
    // apply them to the transformation values
    double newX = tr.transformValues[0] * x + tr.transformValues[1] * y + tr.transformValues[2];
    double newY = tr.transformValues[3] * x + tr.transformValues[4] * y + tr.transformValues[5];
    pt = Point(newX, newY);
    return pt;
}
