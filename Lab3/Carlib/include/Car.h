#ifndef CAR_H
#define CAR_H

class Car {
    private:
        double speed;
    public:
        Car();
        Car(double speed);
        void drive();
        void slow();
        void speedUp();
};



#endif