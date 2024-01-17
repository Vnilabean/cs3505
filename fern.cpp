#include <iostream>

using namespace std; 

const int width = ???; // set width and height as desired
const int height = ???;
const double xMax = 2.75; // keep xMax and yMax at these values
const double yMax = 10.5;

/**
 * Performs the specified number of iterations by repeatedly selecting a transformation function,
 *  applying that transformation, and setting the pixel based on the resulting x and y values. 
 * Note that these tasks are done by calling the functions below.
*/
void performIterations(int iterations, unsigned char* image){

}

/**
 * Randomly selects one of the four transformations with the corresponding probabilities,
 *  returning 0, 1, 2, or 3. Use the rand() function from the standard library (std::rand), 
 * which returns a random integer between 0 and some very large value. 
 * You will want to map this to a more manageable value using the remainder operator(%). 
 * For example, if you mapped the result to integers between 0 and 99, the number 0 would appear with a 1% probability.
 *  Similarly, numbers less than 12 would appear with a 12% probability.
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

/**
 * The given transformation is applied to the values in x and y. 
 * The resulting values are stored in the same x and y variables.
 *  ** see canvas page for visuals on how to do this**
*/
void applyTransformation(double& x, double& y, const double* transformation){

}

/**
 * Sets the pixel that contains the point (x, y) to be drawn in the image.
 *  First you need to determine which pixel by mapping the range of x values to an integer between 0 and width-1, 
 * and the range of y to be between 0 and height-1. 
 * Although you could determine the ranges of x and y through experiment, I provided you with an approximate range.
 *  Values of x will be between -2.75 and 2.75.
 *  Values of y will be between 0.0 and 10.5 (hence the xMax and yMax constants you added above). 
 * To avoid spending too much time on this math problem, try adapting this code for your use:
*/
void setPixel(double x, double y, unsigned char* image) {
    //pixelX = width / 2 + (int)(width * x / xMax / 2);
    //pixelY = (int)(height * y / yMax);
}

/**
 * Returns true if the pixel at the given row and column in the image is set. In other words, that bit has value 1.
*/
bool getPixel(int row, int col, unsigned char* image){

}

/**
 * Draw the image one row at a time by printing to the terminal.
 * If a pixel is set, print "#". If the pixel is not set, print " " (one empty space).
 * Your resulting output will depend on your width, height, and number of iterations.
*/
void drawImage(unsigned char* image) {

}













int main(){
    // initialize the iteration int
    int n = 0;
    // gets user input for the number of iterations
    cin >> n;

    // checks if input of n is not negative
    if(n < 0) {
    cout << "Error: Number of iterations must be non-negative." << endl;    
    }

    return 0;
}