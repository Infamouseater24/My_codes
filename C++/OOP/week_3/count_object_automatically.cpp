//program to count the number of objects created automatically
#include <iostream>

using namespace std;

class ObjectCounter {
private:
    static int count; // Static member variable to count objects

public:
    // Constructor
    ObjectCounter() {
        count++; // Increment count each time an object is created
    }

    // Destructor
    ~ObjectCounter() {
        count--; // Decrement count each time an object is destroyed
    }

    // Static method to retrieve the count
    static int getCount() {
        return count;
    }
};

// Initialize static member variable
int ObjectCounter::count = 0;

int main() {
    // Create objects of ObjectCounter
    ObjectCounter obj1;
    ObjectCounter obj2;
    ObjectCounter obj3;

    // Print the number of objects created
    cout << "Number of objects created: 

