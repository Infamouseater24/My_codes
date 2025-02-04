#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string name;
    int age, grade;
};

int main() {
    cout << "Enter the name, age, and grade of 5 students:\n";

    Student students[5];

    for (int i = 0; i < 5; i++) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Age: ";
        cin >> students[i].age;
        cout << "Grade: ";
        cin >> students[i].grade;
    }

    ofstream Writing_to_file("students.txt");
    if (Writing_to_file.is_open()) {
        for (int i = 0; i < 5; i++) {
            Writing_to_file << "Student " << i + 1 << ":\n";
            Writing_to_file << "Name: " << students[i].name << "\n";
            Writing_to_file << "Age: " << students[i].age << "\n";
            Writing_to_file << "Grade: " << students[i].grade << "\n";
        }
        Writing_to_file.close();
        cout << "Student information written to students.txt\n";
    } else {
        cout << "Unable to open file\n";
    }

    ifstream Reading_to_file("students.txt");
    if (Reading_to_file.is_open()) {
        string line;
        while (getline(Reading_to_file, line)) {
            cout << line << "\n";
        }
        Reading_to_file.close();
    } else {
        cout << "Unable to open file\n";
    }

    return 0;
}