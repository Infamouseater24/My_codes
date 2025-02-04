#include<iostream>
using namespace std;
class Staff{
    public:
    int code;
    string name;
    virtual void getdata(){
        cin >> code;
        cin>> name;
    }
    virtual void display(){
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
    }
};
class Teacher: public Staff{
    string subject;
    public:
    void getdata(){
        Staff::getdata();
        cin >> subject;
    }
    void display(){
        Staff::display();
        cout << "Subject: " << subject << endl;
    }
};
int main(){
    Teacher t[10];
    for(int i=0; i<10; i++){
        t[i].getdata();
    }
    int c;
    cout<<"Teacher"<<endl;
    cin >> c;
    for(int i=0; i<10; i++){
        if(c==t[i].code)
            t[i].display();
    }
    return 0;
}