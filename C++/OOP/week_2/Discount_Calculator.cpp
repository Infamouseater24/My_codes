#include <iostream>
#include <string>
using namespace std;
class Customer {
private:
    string name;
    string product;
    double amountPaid;

public:
    Customer(string name, string product, double amountPaid)
        : name(name), product(product), amountPaid(amountPaid) {}

    double applyDiscount() {
        if (amountPaid > 20000) {
            return amountPaid * 0.95; // 5% discount
        }
        return amountPaid;
    }

    void displayInfo() const {
        cout << "Customer Name: " << name << endl;
        cout << "Product Bought: " << product << endl;
        cout << "Amount Paid: " << amountPaid << endl;
    }
};

int main() {
    Customer cust1("Ram", "Laptop", 25000);
    Customer cust2("Shyam", "Smartphone", 15000);

    cust1.displayInfo();
    cout << "Amount after discount: " << cust1.applyDiscount() << endl;

    cust2.displayInfo();
    cout << "Amount after discount: " << cust2.applyDiscount() << endl;

    return 0;
}
