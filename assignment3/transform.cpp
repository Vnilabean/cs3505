#include "transform.h"
#include <iostream>
/*
Transform class for CS 3505 assignment 2.
By Philippe Gonzalez
Transforms a 2-D point
*/

Transform::Transform() {}

Transform::Transform(double a, double b, double c, double d, double e, double f) {
    transformValues[0] = a;
    transformValues[1] = b;
    transformValues[2] = c;
    transformValues[3] = d;
    transformValues[4] = e;
    transformValues[5] = f;
}

Transform::~Transform() {}

void Transform::getParameters(double parameters[6]){
    for(int i = 0; i < 6; i++){
        parameters[i] = transformValues[i];
    }
}

Point Transform::operator*(Point& oldPoint) {
    // Get the values for the point
    double x = oldPoint.getX();
    double y = oldPoint.getY();
    // apply them to the transformation values
    double newX = transformValues[0] * x + transformValues[1] * y + transformValues[2];
    double newY = transformValues[3] * x + transformValues[4] * y + transformValues[5];
    Point newPoint(newX, newY);
    return newPoint;
}


std::ostream& operator<<(std::ostream& output, Transform tr) {
    // Formatted to assignment specifications of "[a, b, c, d, e, f]"
    output << tr.transformValues[0] << ", " << tr.transformValues[1] << ", " 
    << tr.transformValues[2] << ", " << tr.transformValues[3] << ", " 
    << tr.transformValues[4] << ", " << tr.transformValues[5];

    return output;
}

