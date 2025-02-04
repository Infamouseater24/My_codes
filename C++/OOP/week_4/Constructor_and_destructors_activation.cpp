#include <iostream>
using namespace std;
class parent1{
    public:
        parent1(){
            cout<<"Parent 1 constructor"<<endl;
        }
        ~parent1(){
            cout<<"Parent 1 destructor"<<endl;
        }
};

class parent2{
    protected:
    public:
        parent2(){
            cout<<"Parent 2 constructor"<<endl;
        }
        ~parent2(){
            cout<<"Parent 2 destructor"<<endl;
        }
};

class child: public parent1, public parent2{
    public:
        child(){
            cout<<"Child constructor"<<endl;
        }
        ~child(){
            cout<<"Child destructor"<<endl;
        }
};

int main(){
    child d;
    return 0;
}
