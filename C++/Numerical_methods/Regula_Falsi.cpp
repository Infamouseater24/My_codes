#include <iostream>
#include <cmath>
using namespace std;

float fun(float x){
    return round((pow(x,2)+exp(x)+tan(x)) * 1000) / 1000.0; // Enter function :>
}

int main(){
    float a, b, c, d, x, y, E, E_needed;
    int i = 1;
    cout << "Enter two variables:" << endl;
    cin >> a >> b;
    cout << "Enter error limit:" << endl;
    cin >> E_needed;
    cout<<"i\t\ta\t\tb\t\tc\t\td\t\tx\t\tf(x)\t\tE"<<endl;
    do {
        c = fun(a);
        d = fun(b);
        x = (a * d - b * c) / (d - c);
        y = fun(x);
        E = abs(a - b);
        cout << i++ << "\t\t" << a << "\t\t" << b << "\t\t" << x << "\t\t" << y << "\t\t" << E << "\t\t" << endl;

        if (y > 0) {
            b = x;
        } else {
            a = x;
        }
    } while (abs(E) > E_needed);

    cout << "The root is: " << x << endl;
    return 0;
}