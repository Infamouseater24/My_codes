#include <iostream>
using namespace std;
class Animal {
public:
    virtual void sound() {
        cout << "Animal sound" << endl;
    }
};
class Dog : public Animal {
public:
    void sound() {
        cout << "Dog sound" << endl;
    }
    void eat_food() {
        cout << "Eating dog food" << endl;
    }
};
int main() {
    Dog dog;
    Animal animal = dog;
    dog.sound();
    animal.sound(); 
    // animal.eat_food();
    return 0;
}
