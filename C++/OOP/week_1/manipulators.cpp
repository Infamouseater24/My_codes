#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

ostream & symbol (ostream & output) {
    return output << "Rs";
}

int main() {
    // Initialize variables
    double num1, num2;

    // Prompt the user to enter two numbers
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Print the numbers with the Rs symbol
    cout << setw(10) << "Numbers:" 
         << symbol << setw(10) << fixed << setprecision(2) << num1 
         << symbol << setw(15) << fixed << setprecision(2) << num2 << endl;

    return 0;
}