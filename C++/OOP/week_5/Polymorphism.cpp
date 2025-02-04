#include<iostream>
using  namespace std;
class GP{
public:
    virtual void show() = 0;
};
class P1: virtual public GP{
public:
    void show(){
        cout<<"P1"<<endl;
    }
};
class P2: virtual public GP{
public:
    void show(){
        cout<<"P2"<<endl;
    }
};
class CH:public P1, public P2{
public:
    void show(){
        cout<<"CH"<<endl;
    }
};

int main(){
    CH c;
    return 0;
}