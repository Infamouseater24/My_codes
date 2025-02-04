#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string roll;
    string batch;
    string campus;
    
public:
    Student(string name, string roll) : name(name), roll(roll), batch("2080"), campus("WRC") {}
    
    void display(){
        cout << "Name: " << name << ", Roll Number: " << roll << ", Batch: " << batch << ", Campus: " << campus << endl;
    }
};

int main() {
    int num;
    cout << "enter num of stds: ";
    cin >> num;
    Student** students = new Student*[num];
    cout<< "Enter name and roll : ";
    for(int i=0; i < num;i++) {
        string name ,roll;
        cin>> name >> roll;
        students[i] = new Student(name, roll);
    }
    for (int i = 0; i < num; ++i) students[i]->display();
    
    
    delete[] students;
    return 0;

}
