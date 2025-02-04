
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    fstream file("welcome.txt", ios::in | ios::out | ios::app);

    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    // Writing to the file
    file << "Welcome to the file handling in C++!" << endl;

    // Move the file pointer to the beginning for reading
    file.seekg(0);

    // Reading from the file
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}
