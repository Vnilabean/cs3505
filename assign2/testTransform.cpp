#include "Transform.h"
#include "Point.h"

int main() {

    //  Create the point 1.0, 0
    Point pt(1.0, 0.0);

    // Create a transformation
    double values[6] = {1.0113, -0.1788, 0.0, 0.1788, 1.0113, 0.0};
    Transform tr(values);

    for (int i = 0; i < 200; i++)
    {
        pt *= tr;
        std::cout << pt << std::endl;
    }
    

    
    return 0;
}