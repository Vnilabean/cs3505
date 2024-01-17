#include <iostream>
using namespace std;

class Cat {
private:
    int lives;

public:
    Cat() {
        lives = 9;
    }

    Cat(int initialLives) : lives(initialLives) {}
    
    void reportLives() {
        cout << "I have " << lives << " lives left." << endl;
    }

    void loseLife() {
        lives--;
    }

    Cat& operator+=(int value) {
        lives += value;
        return *this;
    }

    

};


int main() {
    Cat c;
    c.reportLives();
    c.loseLife();
    c.reportLives();
    (c += 5) += 5;
    c.reportLives();
    Cat d(5);
    d.reportLives();
    return 0;
}