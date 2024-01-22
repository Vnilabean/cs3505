/**
 *  Name: Philippe Gonzalez
 *  CS3505 
 *  Assignment 1
 *  This is a program that draws a fractal fern using the Barnsley Fern algorithm
 **/

#include <iostream>

using namespace std; 

const int width = 240; // set width and height as desired
const int height = 240;
const double xMax = 2.75; // keep xMax and yMax at these values
const double yMax = 10.5;
// initialize the transformation values using an array of arrays: array x is funciton number and y is values
const double transformValues[4][6] = {
        {0, 0, 0, 0, 0.16, 0},
        {0.85, 0.04, 0, -0.04, 0.85, 1.6},
        {0.20, -0.26, 0, 0.23, 0.22, 1.6},
        {-0.15, 0.28, 0, 0.26, 0.24, 0.44}
};

// declare the functions that will be used
int selectTransformation();
void applyTransformation(double& x, double& y, const double* transformation);
void setPixel(double x, double y, unsigned char* image);


/**
 * Performs the specified number of iterations by repeatedly selecting a transformation function,
 *  applying that transformation, and setting the pixel based on the resulting x and y values. 
*/
void performIterations(int iterations, unsigned char* image){

    // set x and y
    double x = 0.0;
    double y = 0.0;
    for(int i = 0; i < iterations; i++){
        // select transformation
        int transformation = selectTransformation();
        // apply transformation
        applyTransformation(x, y, transformValues[transformation]);
        // set pixel
        setPixel(x, y, image);
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

/**
 * The given transformation is applied to the values in x and y. 
*/
void applyTransformation(double& x, double& y, const double* transformation){
    double newX = transformation[0] * x + transformation[1] * y + transformation[2];
    double newY = transformation[3] * x + transformation[4] * y + transformation[5];
    x = newX;
    y = newY;
}

/**
 * Sets the pixel that contains the point (x, y) to be drawn in the image.
*/
void setPixel(double x, double y, unsigned char* image) {
    // pixelx and pixely used from canvas posting for assignment
    int pixelX = width / 2 + (int)(width * x / xMax / 2);
    int pixelY = (int)(height * y / yMax);
    // row = width * pixelY  column = pixelX
    int pixel = width * pixelY + pixelX;
    int bit = pixel % 8;
    int index = pixel / 8;
    // sets the bit to the correct position based on pixel%8 then bitwise ands it with the current image array index
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
*/
void drawImage(unsigned char* image) {
    for(int i = height - 1; i >= 0; i--){
        for(int z = 0; z < width; z++){
            if(getPixel(i, z, image)){
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    // initialize the iteration int
    int n = 0;

    // gets user input for the number of iterations
    cout << "Number of iterations: ";
    cin >> n;

    // checks if input of n is not negative
    if(n <= 0 || typeid(n) != typeid(int)) {
    cout << "Error: Number of iterations must be non-negative and an integer." << endl;    
    return 0;
    }

    // create image array
    unsigned char image[width * height / 8] = {0};

    // calls the performIterations function which delegates the functions needed
    performIterations(n, image);

    // calls the drawImage function which prints the image
    drawImage(image);

    return 0;
}