#include <iostream>

using namespace std; 

const int width = 120; // set width and height as desired
const int height = 120;
const double xMax = 2.75; // keep xMax and yMax at these values
const double yMax = 10.5;
// initialize the transformation values using an array of arrays: array x is funciton number and y is values
const double transformValues[4][6] = {
        {0, 0, 0, 0, 0.16, 0},
        {0.85, 0.04, 0, -0.04, 0.85, 1.6},
        {0.20, -0.26, 0, 0.23, 0.22, 1.6},
        {-0.15, 0.28, 0, 0.26, 0.24, 0.44}
    };
// declare the functions that will be used out of order
int selectTransformation();
void applyTransformation(double& x, double& y, const double* transformation);
void setPixel(double x, double y, unsigned char* image);


/**
 * Performs the specified number of iterations by repeatedly selecting a transformation function,
 *  applying that transformation, and setting the pixel based on the resulting x and y values. 
 * Note that these tasks are done by calling the functions below.
*/
void performIterations(int iterations, unsigned char* image){

    for(int i = 0; i < iterations; i++){
        // select transformation
        int transformation = selectTransformation();
        // get x and y
        double x = 0;
        double y = 0;
        // apply transformation
        applyTransformation(x, y, transformValues[transformation]);
        // set pixel
        setPixel(x, y, image);
        x++;
        y++;
    }

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
    double newX = transformation[0] * x + transformation[1] * y + transformation[2];
    double newY = transformation[3] * x + transformation[4] * y + transformation[5];
    x = newX;
    y = newY;
}

/**
 * Sets the pixel that contains the point (x, y) to be drawn in the image.
 *  First you need to determine which pixel by mapping the range of x values to an integer between 0 and width-1, 
 * and the range of y to be between 0 and height-1. 
 * Although you could determine the ranges of x and y through experiment, I provided you with an approximate range.
 *  Values of x will be between -2.75 and 2.75.
 *  Values of y will be between 0.0 and 10.5 (hence the xMax and yMax constants you added above). 
*/
void setPixel(double x, double y, unsigned char* image) {
    int pixelX = width / 2 + (int)(width * x / xMax / 2);
    int pixelY = (int)(height * y / yMax);
    int pixel = pixelY * width + pixelX;
    int bit = pixel % 8;
    int index = pixel / 8;
    image[index] = image[index] | (1 << bit);
}

/**
 * Returns true if the pixel at the given row and column in the image is set. In other words, that bit has value 1.
*/
bool getPixel(int row, int col, unsigned char* image){
    int pixel = row * width + col;
    int bit = pixel % 8;
    int index = pixel / 8;
    return (image[index] & (1 << bit)) != 0;
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
    cout << "Number of iterations: ";
    cin >> n;

    // checks if input of n is not negative
    if(n < 0) {
    cout << "Error: Number of iterations must be non-negative." << endl;    
    }

    // create image array
    unsigned char image[(width * height) / 8] = {0};

    // calls the performIterations function which delegates the functions needed
    performIterations(n, image);

    // calls the drawImage function which prints the image
    drawImage(image);

    return 0;
}