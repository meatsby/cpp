#include <iostream>

using namespace std;

class Animal {
public:
    virtual void sayHi() {
        cout << "..." << endl;
    }
};

class Human : public Animal {
public:
    void sayHi() {
        cout << "hi" << endl;
    }
};

class Dog : public Animal {
public:
    void sayHi() {
        cout << "wow wow" << endl;
    }
};

int main() {
    Human *human = new Human();
    Dog *dog = new Dog();

    Animal *a;  // static type of "a" is Animal
    a = human;  // dynamic type of "a" is Human
    a->sayHi(); // will print "hi"
    a = dog;    // dynamic type of "a" is Dog
    a->sayHi(); // will print "wow wow"

    delete human;
    delete dog;
    return 0;
}
