#include <iostream>
using namespace std;

class test_class {
private:
    static int c;

public:
    test_class() {
        c++;
    }

    static int getCount() {
        return c;
    }
};
int test_class::c = 0;
int main() {
    test_class obj1, obj2, obj3;
    cout << "Number of objects created: " << test_class::getCount() << endl; 
    return 0;
}
