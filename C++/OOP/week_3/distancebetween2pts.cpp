//program to calculate distance between two points.Each points is represented in (m,km) using oop concept
#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double meters;
    double kilometers;

public:
    // Constructor
    Point(double m, double km) {
        meters = m;
        kilometers = km;
    }

    // Method to calculate distance to another Point
    double distanceTo(Point otherPoint) {
        // Convert both points to meters for calculation
        double point1InMeters = meters + kilometers * 1000;
        double point2InMeters = otherPoint.meters + otherPoint.kilometers * 1000;

        // Calculate the Euclidean distance between two points
        double distanceInMeters = fabs(point1InMeters - point2InMeters);

        return distanceInMeters;
    }
};

int main() {
    // Create two points
    Point point1(500, 2);   // 500 meters + 2 kilometers
    Point point2(300, 1.5); // 300 meters + 1.5 kilometers

    // Calculate distance between points
    double distance = point1.distanceTo(point2);

    // Output the distance
    cout << "The distance between the points is " << distance << " meters." << endl;

    return 0;
}

