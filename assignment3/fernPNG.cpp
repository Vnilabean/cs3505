/**
 * @author: Philippe Gonzalez
 * @note: CS3505 Assignment 3
*/

#include "transform.h"
#include "point.h"
#include "pngWriter.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
using namespace std; 


// initialize the transformation values
Transform t1 = Transform(0, 0, 0, 0, 0.16, 0);
Transform t2 = Transform(0.85, 0.04, 0, -0.04, 0.85, 1.6);
Transform t3 = Transform(0.20, -0.26, 0, 0.23, 0.22, 1.6);
Transform t4 = Transform(-0.15, 0.28, 0, 0.26, 0.24, 0.44);
const double xMax = 2.75;
const double yMax = 10.5;
int selectTransformation();

/**
 * Performs the specified number of iterations by repeatedly selecting a transformation function,
 *  applying that transformation, and setting the pixel based on the resulting x and y values. 
*/
void applyIterations(int iterations, PNGWriter& png, int width, int height){
    Point p = Point(0, 0);
    for(int i = 0; i < iterations; i++){
        // select transformation
        int transformation = selectTransformation();
        // apply transformation
        switch(transformation){
            case 0:
                p = t1 * p;
                break;
            case 1:
                p = t2 * p;
                break;
            case 2:
                p = t3 * p;
                break;
            case 3:
                p = t4 * p;
                break;
        }
        // get pixel corrdinates value then set it
        int pixelX = width / 2 + (int)(width * p.getX() / xMax / 2);
        int pixelY = height - (int)(height * p.getY() / yMax); 
        // set pixel to green
        png.setPixel(pixelX, pixelY, 104, 160, 100, 255);
    }
}

/**
 * Randomly selects one of the four transformations with the corresponding probabilities,
 *  returning 0, 1, 2, or 3. 
*/
int selectTransformation(){
    int randNum = std::rand();
    randNum = randNum % 100;
    if(randNum == 0){
        return 0;
    } else if(randNum < 86){
        return 1;
    } else if(randNum < 93){
        return 2;
    } else {
        return 3;
    }

}


int main(int argc, char *argv[]) {
    int width;
    int height;
    // check for valid number of arguments
    if(argc != 5){
        cout << "Requires 4 arguments: filename, width, height, iterations" << endl;
        return 0;
    }
    // get width and height from arguments
    stringstream widthStream(argv[2]);
    stringstream heightStream(argv[3]);
    widthStream >> width;
    heightStream >> height;
    // check for valid width and height
    if(width < 1 || height < 1){
    cout << "Width and height were not valid values > 0" << endl;
    return 0;
    }
    // create PNGWriter object and apply iterations
    PNGWriter png = PNGWriter(width, height);
    applyIterations(stoi(argv[4]), png, width, height);
    png.writePNGFile(argv[1]);
    return 0;
}