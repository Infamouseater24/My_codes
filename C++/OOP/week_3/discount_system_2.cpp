//Create a class customer with attributes customer name, product bought and paid amount.
//Create a suitable methods to take and display the information with a clause that if amount 
//paid is greater than 20000 then discount of 5% given else no discount is granted.
#include <iostream>
#include <string>

using namespace std;

class Customer {
private:
    string customerName;
    string productBought;
    double paidAmount;
    double discount;

public:
    // Constructor to initialize customer details
    Customer(string name, string product, double amount) {
        customerName = name;
        productBought = product;
        paidAmount = amount;
        calculateDiscount();
    }

    // Method to set customer details
    void setDetails(string name, string product, double amount) {
        customerName = name;
        productBought = product;
        paidAmount = amount;
        calculateDiscount();
    }

    // Method to calculate discount based on paid amount
    void calculateDiscount() {
        if (paidAmount > 20000) {
            discount = 0.05 * paidAmount; // 5% discount
        } else {
            discount = 0.0; // No discount
        }
    }

    // Method to display customer details including discount
    void display() {
        cout << "Customer Name: " << customerName << endl;
        cout << "Product Bought: " << productBought << endl;
        cout << "Paid Amount: $" << paidAmount << endl;
        if (discount > 0.0) {
            cout << "Discount Given: $" << discount << endl;
            cout << "Final Amount Paid: $" << (paidAmount - discount) << endl;
        } else {
            cout << "No Discount Given." << endl;
            cout << "Final Amount Paid: $" << paidAmount << endl;
        }
    }
};

int main() {
    // Create a customer object and set details
    Customer customer1("John Doe", "Laptop", 25000.0);

    // Display customer details
    cout << "Customer 1 Details:" << endl;
    customer1.display();
    cout << endl;

    // Create another customer object and set details using method
    Customer customer2("", "", 0.0);
    customer2.setDetails("Jane Smith", "Smartphone", 15000.0);

    // Display customer details
    cout << "Customer 2 Details:" << endl;
    customer2.display();

    return 0;
}

