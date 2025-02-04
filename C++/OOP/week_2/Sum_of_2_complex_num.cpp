#include <iostream>
using namespace std;
class Complex {
private:
    double real;
    double imag;
    
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex add(Complex other){
        return Complex(real + other.real, imag + other.imag);
    }

    void display(){
        cout<< real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);

    Complex sum = c1.add(c2);
    cout<< "Sum of complex numbers: ";
    sum.display();

    return 0;
}
