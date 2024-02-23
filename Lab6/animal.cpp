#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal
{
protected:
    double age;
    string name;

public:
    Animal(string name) : name(name), age(0){};
    virtual void speak()
    {
        cout << "I am an Animal named " << name << endl;
    }
    void talk(){
    speak();
}
};

class Cat : public Animal
{
    bool isHouseCat;

public:
    Cat(string catName, bool houseCat) : Animal(catName), isHouseCat(houseCat){};

    virtual void speak()
    {
        cout << "Meow"
             << " and I am " << name << " and my housecatness is " << isHouseCat << endl;
    }
};

class Cow : public Animal
{
public:
    Cow(string cowName) : Animal(cowName){};
    virtual void speak()
    {
        cout << "Moo"
             << " and I am " << name << endl;
    }
};

int main()
{
    Animal a("Fido");
    Cat c("Whiskers", true);
    Cow d("Bessie");
    a.speak();
    c.speak();
    d.speak();
    std::vector<Animal *> animals;
    animals.push_back(&a);
    animals.push_back(&c);
    animals.push_back(&d);
    for (auto animal : animals)
    {
        animal->speak();
    }

    Animal* animalPtr = new Cat("Whiskers", true);
    animalPtr->talk();
    
    return 0;
}
