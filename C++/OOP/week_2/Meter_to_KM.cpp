#include <iostream>
#include <cmath>
using namespace std;
class Point {
private:
    double x_cordinate;
    double y_cordinate;
    
public:
    Point(double x = 0, double y = 0) : x_cordinate(x), y_cordinate(y) {}
    
    double in_meters(Point second){
        double dx = x_cordinate - second.x_cordinate;
        double dy = y_cordinate - second.y_cordinate;
        return sqrt(dx * dx + dy * dy);
    }

    double in_kilometers(Point second){
        return in_meters(second) / 1000; // Convert meters to kilometers
    }
};

int main() {
    Point p1(0, 0);
    Point p2(3000.5, 4000);

    cout<< "Distance in meters: " << p1.in_meters(p2) << endl;
    cout<< "Distance in kilometers: " << p1.in_kilometers(p2) << endl;

    return 0;
}
