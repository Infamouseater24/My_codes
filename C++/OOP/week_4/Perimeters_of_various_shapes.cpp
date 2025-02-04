#include <iostream>
using namespace std;

class SHAPE{
    protected:
    int value;
    public:
    SHAPE(int v){
        value = v;
    }
    virtual void FindPerimeter(){}
};class SQUARE: public SHAPE{
    public:
    SQUARE(int v): SHAPE(v){
    }
    void FindPerimeter(){
        cout << "Perimeter of square: " << 4 * value << endl;
    }
};

class CIRCLE: public SHAPE{
    public:
    CIRCLE(int v): SHAPE(v){
    }
    void FindPerimeter() {
        cout << "Circumference of circle: " << 2 * 3.14 * value << endl;
    }
};

int main(){
    SQUARE s(5);
    CIRCLE c(5);
    s.FindPerimeter();
    c.FindPerimeter();
    return 0;
}
