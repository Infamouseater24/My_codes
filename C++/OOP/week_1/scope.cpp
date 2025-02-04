#include<iostream>
using namespace std;
static int m = 0;
class Counter{
    public:
    Counter(){
    ::m++;
    }
};

int main(){
   Counter counter1, counter2, counter3, counter4, counter5, counter6, counter7, counter8, counter9;
   cout << "Total number of objects created: " << ::m << endl;
   return 0;
}