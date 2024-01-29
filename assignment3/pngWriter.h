#ifndef PNGWRITER_H
#define PNGWRITER_H

#include "png.h"


/**
 * @class PNGWriter
 * @brief A class for writing PNG files
 */
class PNGWriter {

private:
    int width;
    int height; 
    unsigned char* imageData;
    png_bytep* imageRows;

public:
    /**
     * @brief Constructs a PNGWriter object with default width and height
    */
    PNGWriter();

    /**
     * @brief Constructs a PNGWriter object with the specified width and height
     * @param width The width of the image
     * @param height The height of the image
     */
    PNGWriter(int width, int height);

    /**
     * @brief Destroys the PNGWriter object
     */
    ~PNGWriter();

    /**
     * @brief Writes the image data to a PNG file with the specified filename including ".png"
     * @param filename The name of the PNG file to write
     */
    void writePNGFile(char *filename);

    /**
     * @brief Sets the pixel at the specified coordinates
     * @param x The x coordinate of the pixel
     * @param y The y coordinate of the pixel
     */
    void setPixel(int x, int y);


};
#endif