#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <iostream>
#include "point.h"
class Point;

/**
 * @brief A transform class that represents a 2D point transformation
 * @author Philippe Gonzalez
 * @note CS3505 Assignment 2
 */
class Transform {
private:
    // values of the transformation
    double transformValues[6];

public:
    /**
     * @brief The default constructor
     */
    Transform();

    /**
     * @brief Constructor that initializes the transformation array with the given values
     */
    Transform(double a, double b, double c, double d, double e, double f);

    /**
     * @brief Destructor for the transform class
     */
    ~Transform();

    /**
     * @brief Sets the values of the transformation array to the given array
     * @param parameters A pointer to an array of double pointers to store the parameters
     */
    void getParameters(double parameters[6]);

    /**
     * @brief Overloaded multiplication operator to transform a Point object using the transformation values
     * @param oldPoint The Point object to be transformed
     * @return The transformed Point object
     */
    Point operator*(Point& oldPoint);

    /**
     * @brief Overloaded *= assignment operator to transform a Point object using the transformation values
     * @param pt The Point object to be transformed
     * @param tr The Transform object representing the transformation values
     * @return The transformed Point object
     */
    friend Point& operator*=(Point& pt, Transform tr);

    /**
     * @brief Overloaded stream operator to output the transformation values
     * @param output The output stream object
     * @param tr The Transform object to be output
     * @return The output stream object
     */
    friend std::ostream& operator<<(std::ostream& output, Transform tr);
};

#endif
    