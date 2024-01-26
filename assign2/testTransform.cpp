#include "transform.h"
#include "point.h"

int main() {

    //  Create the point 1.0, 0
    Point pt(1.0, 0.0);

    // points for my run of transform
    // -1.06, -0.000788, 0.55555, 0.9954, 1.0512, 1.0

    Transform tr(1.0113, -0.1788, 0.0, 0.1788, 1.0113, 0.0);

    for (int i = 0; i < 200; i++)
    {
        pt *= tr;
        std::cout << pt << std::endl;
    }
    

    
    return 0;
}