//program to show constructor overloading
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;
    double gpa;

public:
    // Default constructor
    Student() {
        name = "Unknown";
        age = 0;
        gpa = 0.0;
    }

    // Parameterized constructor with name and age
    Student(string n, int a) {
        name = n;
        age = a;
        gpa = 0.0; // Default GPA
    }

    // Parameterized constructor with all attributes
    Student(string n, int a, double g) {
        name = n;
        age = a;
        gpa = g;
    }

    // Method to display student details
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "GPA: " << gpa << endl;
        cout << endl;
    }
};

int main() {
    // Create objects using different constructors
    Student student1; // Default constructor
    Student student2("John Doe", 20); // Parameterized constructor with name and age
    Student student3("Jane Smith", 22, 3.75); // Parameterized constructor with all attributes

    // Display student details
    cout << "Student 1 Details:" << endl;
    student1.display();

    cout << "Student 2 Details:" << endl;
    student2.display();

    cout << "Student 3 Details:" << endl;
    student3.display();

    return 0;
}

