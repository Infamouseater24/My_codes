#include<iostream>
using namespace std;
class student{
    protected:
      int roll;
    public:
        void sget(){
            cout<<"Enter roll number: ";
            cin>>roll;
        }
        void sdisplay(){
            cout<<"Roll number: "<<roll<<endl;
        }

};
class test : virtual public student{
    protected:
        string name;
    public:
        void tget(){
            cout<<"Enter name: ";
            cin>>name;
        }
        void tdisplay(){
            cout<<"Name: "<<name<<endl;
        }
};
class sports: virtual public student{
    protected: 
        int price;
    public:
        void ssget(){
            cout<<"Enter sports price: ";
            cin>>price;
        }
        void ssdisplay(){
            cout<<"Price: "<<price<<endl;
        }
};

class result : public test, public sports{
    protected:
        int fee;
    public:
        void rget(){
            cout<<"Enter result fee: ";
            cin>>fee;
        }
        void rdiplay(){
            cout<<"Fee: "<<fee<<endl;
        }
};

int main(){
    result test;
    test.sget();
    test.tget();
    test.ssget();
    test.rget();
    test.sdisplay();
    test.tdisplay();
    test.ssdisplay();
    test.rdiplay();
    return 0;
}