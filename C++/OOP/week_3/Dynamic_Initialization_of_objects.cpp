//the program to show dynamic initialization of an object of class 
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // Constructor
    Student(string n, int a) {
        name = n;
        age = a;
    }

    // Method to display student details
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Dynamic initialization of a Student object
    Student *studentPtr = new Student("John Doe", 20);

    // Call display method using pointer to object
    cout << "Student Details (Dynamic Initialization):" << endl;
    studentPtr->display();

    // Deallocate memory
    delete studentPtr;

    return 0;
}

