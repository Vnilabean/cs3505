#ifndef POINT_H
#define POINT_H
/*
Point class for CS 3505 lecture 3.
A Point holds x and y values.
By Eric Heisler and Philippe Gonzalez
*/

#include <iostream> // for ostream
#include "Transform.h"
class Transform;

/**
 * @brief A Point class that represents a point in 2D
 * This class provides a way to store and manipulate the coordinates of a 2D point
 */
class Point {
private:
    double x, y;  // The x and y coordinates of the point

public:

    /**
     * @brief Default constructor that initializes the point to 0, 0
     */
    Point();

    /**
     * @brief The constructor that initializes the point with the given x, y coordinates
     * 
     * @param initX initial x coordinate of the point
     * @param initY initial y coordinate of the point
     */
    Point(double initX, double initY);

    /**
     * @brief Destructor for the Point class
     * 
     * The  destructor does nothing in this class
     */
    ~Point();

    /**
     * @brief Getter for the x coordinate of the point
     * 
     * @return The x coordinate of the point
     */
    double getX();

    /**
     * @brief Getter for the y coordinate of the point
     * 
     * @return The y coordinate of the point
     */
    double getY();

    /**
     * @brief Overloaded multiplication operator
     * 
     * @param scaleFactor The factor by which to scale the point
     * @return The scaled point
     */
    Point operator*(double scaleFactor);

    /**
     * @brief Friend insertion operator to enable easy printing of Point objects
     * 
     * @param output The output to write to
     * @param pt The Point object to be printed
     * @return The output stream
     */
    friend std::ostream& operator<<(std::ostream& output, Point pt);

    /**
     * @brief Friend operator to perform scaling of a Point object
     * 
     * @param pt The Point object to be scaled
     * @param tr The Transform object representing the scaling transformation
     * @return The scaled Point object
     */
    friend Point& operator*=(Point& pt, Transform tr);
};

#endif // include guard for POINT_H