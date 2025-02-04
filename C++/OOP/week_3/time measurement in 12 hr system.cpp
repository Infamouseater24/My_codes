//program that creates a class which represents time measurement in 12 hr system
#include <iostream>
#include <iomanip>

using namespace std;

class Time12 {
private:
    int hour;
    int minute;
    string period; // "AM" or "PM"

public:
    // Constructor to initialize time
    Time12(int h, int m, string p) {
        hour = h;
        minute = m;
        period = p;
    }

    // Method to display time in 12-hour format
    void displayTime() {
        cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << " " << period << endl;
    }
};

int main() {
    // Create an object of Time12 and display time
    Time12 time1(9, 30, "AM");
    time1.displayTime();

    Time12 time2(2, 45, "PM");
    time2.displayTime();

    return 0;
}

