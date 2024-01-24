#include <iostream>
#include "Car.h"

 Car::Car() {}

Car::Car(double speed) {
    Car::speed = speed;
}
void Car::drive() {
    std::cout << "Zooming " << speed << " mph."<< std::endl;
}

void Car::slow() {
    speed = speed / 2;
}

void Car::speedUp() {
    speed = speed * 1.5;
}



