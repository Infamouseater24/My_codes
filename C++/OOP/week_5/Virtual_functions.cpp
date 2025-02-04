#include <iostream>
using namespace std;
class Animal {
public: 
    virtual string getColor() {
        return "Unknown";
    }
};
class Dog : public Animal {
public:
    
    string getColor() override{
        return "Black";
    }
};
int main(){
    Dog dog;
    Animal* animal = new Dog();
    cout << animal->getColor() << endl;
    delete[] animal;
    return 0;
}