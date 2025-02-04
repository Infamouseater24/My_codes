#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
    int num;
    char ch;
    string text;

    cout << "Enter an integer: ";
    cin >> num;
    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter a line of text: ";
    cin>> text;


    ofstream Writing_to_file("output.txt");
    Writing_to_file.put(num);
    Writing_to_file.put(ch);
    Writing_to_file.write(text.c_str(), text.length());


    ifstream inputFile("output.txt");

    inputFile.get(ch);
    getline(inputFile, text);

    cout << "Entered integer: " << num << endl;
    cout << "Entered character: " << ch << endl;
    cout << "Entered text: " << text << endl;

    cout << "Message" << endl;

    return 0;
}