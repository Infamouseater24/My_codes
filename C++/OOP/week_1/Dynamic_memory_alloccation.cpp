#include<iostream>
using namespace std;
class File{
    private:
    int data1, data2;
    public:
    void setter(int d1, int d2){
        data1 = d1;
        data2 = d2;  // access private members directly using setter function
    }
    void display(){
        cout << "Data1: " << data1 << endl;
        cout << "Data2: " << data2 << endl; 
    }
};
int main(){
    File* file = new File;
    file->setter(10, 20);
    file->display();

    delete file;
    return 0;   
}