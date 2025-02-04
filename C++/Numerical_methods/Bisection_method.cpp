#include <iostream>
#include <cmath>
using namespace std;
float fun(float x){
    return round((pow(x,2)+exp(x)+tan(x)) * 10000) / 10000.0; // Enter function :>
}
int main(){
    float a,b,x,y,E,E_needed,i=1;
    cout << "2 variables" << endl;
    cin >> a >> b;
    cout <<"error limit"   << endl;
    cin >> E_needed;
    cout << "i\ta\tb\tx\ty\tE" << endl;
    do {
        x  = (a + b) /2;
        y = fun(x);
        E = abs(a - b);
        cout << i++ << "\t" << a << "\t" << b << "\t" << x << "\t" << y << "\t" << E << "\t" << endl;

        if (y > 0) {
            b = x;
        } else {
            a = x;
        }
    } while (abs(E) > E_needed);

    cout << "The root is: " << x << endl;
    return 0;
}
