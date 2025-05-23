/**
 * @author Philippe Gonzalez
 * @note CS3505 Assignment 3
 * @note Most of the code in this file is from the examplePNG code, just formatted to work for the assignment
*/

#include "pngWriter.h"
#include "png.h"
#include <stdlib.h>

int width;
int height;
unsigned char* imageData;
png_bytep* imageRows;

PNGWriter::PNGWriter() {}

/**
 * @brief Constructs a PNGWriter object with the specified width and height
*/
PNGWriter::PNGWriter(int width, int height) {
    this->width = width;
    this->height = height;
    // Set the image data and rows to the correct size
    imageData = new unsigned char[height * width * 4] {};
    imageRows = new png_bytep[height] {};
}

/**
 * @brief Destroys the PNGWriter object
*/
PNGWriter::~PNGWriter() {
    delete[] imageData;
    delete[] imageRows;
}

/**
 * @brief Writes the image data to a PNG file with the specified filename
*/
void PNGWriter::writePNGFile(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if(!fp) abort();
    
    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) abort();
    
    png_infop info = png_create_info_struct(png);
    if (!info) abort();
    
    if (setjmp(png_jmpbuf(png))) abort();
    
    png_init_io(png, fp);
    // Output is 8bit depth, RGBA format.
    png_set_IHDR(
        png,
        info,
        width, height,
        8,
        PNG_COLOR_TYPE_RGBA,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT
    );
    
    // pnglib requires the image stored as rows
    for(int y = 0; y < height; y++) {
        imageRows[y] = &imageData[y * width * 4];
    }
    
    // These three commands write the png file
    png_write_info(png, info);
    png_write_image(png, imageRows);
    png_write_end(png, NULL);
    
    fclose(fp);

    png_destroy_write_struct(&png, &info);
}

 /**
  * @brief Sets the pixel at the specified coordinates
 */
void PNGWriter::setPixel(int x, int y, int red, int green, int blue, int alpha) {
    // offset used from the exmaple
    int offset = (y * width + x) * 4;

    // Set the pixel to specified color
    imageData[offset] = red;       
    imageData[offset + 1] = green;   
    imageData[offset + 2] = blue;   
    imageData[offset + 3] = alpha; 
    
}

/**
 * @brief Sets the pixel at the specified coordinates to black
*/
void PNGWriter::setPixel(int x, int y) {
    setPixel(x, y, 0, 0, 0, 255);
}
