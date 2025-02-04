#include <iostream>
using namespace std;
class Prime_test{
private:
    int number;
    
public:
    Prime_test(int number) : number(number) {}
    
    bool isPrime(){
        if (number <= 1) return false;
        for (int i = 2; i < number; ++i) {
            if (number % i == 0) return false;
        }
        return true;
    }
};

int main() {
    int num;
    cout << "Enter a number: ";
    cin>> num;
    
    Prime_test test_number(num);
    if (test_number.isPrime()) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }

    return 0;
}
