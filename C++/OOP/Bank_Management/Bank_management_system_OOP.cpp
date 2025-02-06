#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> // For system("pause")

using namespace std;

class Account {
private:
    string accountName;
    int accountNumber;
    double balance;

public:
    Account(string name, int number, double bal)
        : accountName(name), accountNumber(number), balance(bal) {
        // Create the initial transaction log file with account details
        ofstream outFile(to_string(accountNumber) + ".txt");
        if (outFile) {
            outFile << "Account Name: " << accountName << endl;
            outFile << "Account Number: " << accountNumber << endl;
            outFile.close();
        } else {
            cerr << "Error: Unable to create transaction record for account " << accountNumber << endl;
        }
    }

    string getAccountName() const {
        return accountName;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            recordTransaction("Deposit", amount);
            updateBalanceFile(); // Update balance in accounts.txt
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            recordTransaction("Withdraw", amount);
            updateBalanceFile(); // Update balance in accounts.txt
            return true;
        }
        return false;
    }

    void displayAccountDetails() const {
        cout << "Account Name: " << accountName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    void recordTransaction(const string& type, double amount) {
        ofstream outFile(to_string(accountNumber) + ".txt", ios::app);
        if (outFile) {
            outFile << type << ": " << amount << " Balance: " << balance << endl;
            outFile.close();
        } else {
            cerr << "Error: Unable to open transaction record for account " << accountNumber << endl;
        }
    }

    void updateBalanceFile() const {
        ifstream inFile("accounts.txt");
        if (!inFile) {
            cerr << "Error: Unable to open accounts.txt for update." << endl;
            return;
        }

        ofstream outFile("temp.txt");
        if (!outFile) {
            cerr << "Error: Unable to create temp.txt for update." << endl;
            inFile.close();
            return;
        }

        string name;
        int number;
        double bal;
        bool found = false;

        while (inFile >> name >> number >> bal) {
            if (number == accountNumber) {
                outFile << name << " " << number << " " << balance << endl;
                found = true;
            } else {
                outFile << name << " " << number << " " << bal << endl;
            }
        }

        if (!found) {
            outFile << accountName << " " << accountNumber << " " << balance << endl;
        }

        inFile.close();
        outFile.close();

        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");
    }
};

vector<Account> accounts;

// Function declarations
void showMenu();
void handleUserInput();
void loadAccounts();
void saveAccounts();
void createAccount();
void depositMoney();
void withdrawMoney();
void transferMoney();
void showAccountDetails();

// Main function
int main() {
    loadAccounts();
    handleUserInput();
    saveAccounts();
    return 0;
}

// Function to show the main menu
void showMenu() {
    cout << "Banking Management System" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Transfer Money" << endl;
    cout << "5. Show Account Details" << endl;
    cout << "6. Exit" << endl;
}

// Function to handle user input
void handleUserInput() {
    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                transferMoney();
                break;
            case 5:
                showAccountDetails();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        // Pause and wait for user to press any key
        if (choice >= 1 && choice <= 5) {
            cout << "Press any key to continue...";
            cin.ignore(); // Ignore previous newline character
            cin.get();    // Wait for user to press Enter
            system("cls"); // Clear screen (Windows specific)
        }

    } while (choice != 6);
}

// Function to load accounts from a file
void loadAccounts() {
    ifstream inFile("accounts.txt");
    if (!inFile) {
        cout << "No existing account data found. Starting fresh." << endl;
        return;
    }

    string name;
    int number;
    double balance;
    while (inFile >> name >> number >> balance) {
        accounts.emplace_back(name, number, balance);
    }
    inFile.close();
}

// Function to save accounts to a file
void saveAccounts() {
    ofstream outFile("accounts.txt");
    for (const auto& account : accounts) {
        outFile << account.getAccountName() << " "
                << account.getAccountNumber() << " "
                << account.getBalance() << endl;
    }
    outFile.close();
}

// Function to create a new account
void createAccount() {
    string name;
    int number;
    double initialBalance;

    cout << "Enter account name: ";
    cin >> name;
    cout << "Enter account number: ";
    cin >> number;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    Account newAccount(name, number, initialBalance);
    accounts.push_back(newAccount);
    cout << "Account created successfully!" << endl;
}

// Function to deposit money into an account
void depositMoney() {
    int number;
    double amount;
    cout << "Enter account number: ";
    cin >> number;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    for (auto& account : accounts) {
        if (account.getAccountNumber() == number) {
            account.deposit(amount);
            cout << "Amount deposited successfully!" << endl;
            return;
        }
    }
    cout << "Account not found!" << endl;
}

// Function to withdraw money from an account
void withdrawMoney() {
    int number;
    double amount;
    cout << "Enter account number: ";
    cin >> number;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    for (auto& account : accounts) {
        if (account.getAccountNumber() == number) {
            if (account.withdraw(amount)) {
                cout << "Amount withdrawn successfully!" << endl;
            } else {
                cout << "Insufficient balance!" << endl;
            }
            return;
        }
    }
    cout << "Account not found!" << endl;
}

// Function to transfer money between accounts
void transferMoney() {
    int sourceNumber, destinationNumber;
    double amount;

    cout << "Enter source account number: ";
    cin >> sourceNumber;
    cout << "Enter destination account number: ";
    cin >> destinationNumber;
    cout << "Enter amount to transfer: ";
    cin >> amount;

    Account* sourceAccount = nullptr;
    Account* destinationAccount = nullptr;

    for (auto& account : accounts) {
        if (account.getAccountNumber() == sourceNumber) {
            sourceAccount = &account;
        }
        if (account.getAccountNumber() == destinationNumber) {
            destinationAccount = &account;
        }
    }

    if (sourceAccount == nullptr) {
        cout << "Source account not found!" << endl;
        return;
    }

    if (destinationAccount == nullptr) {
        cout << "Destination account not found!" << endl;
        return;
    }

    if (sourceAccount->withdraw(amount)) {
        destinationAccount->deposit(amount);
        sourceAccount->recordTransaction("Transfer to " + to_string(destinationNumber), amount);
        destinationAccount->recordTransaction("Transfer from " + to_string(sourceNumber), amount);
        cout << "Amount transferred successfully!" << endl;
    } else {
        cout << "Insufficient balance in source account!" << endl;
    }
}

// Function to show account details
void showAccountDetails() {
    int number;
    cout << "Enter account number: ";
    cin >> number;

    for (const auto& account : accounts) {
        if (account.getAccountNumber() == number) {
            ifstream inFile(to_string(number) + ".txt");
            if (!inFile) {
                cout << "Error: Unable to open transaction record for account " << number << endl;
                return;
            }
            
            string line;
            // Output account details from file
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();

            return;
        }
    }
    cout << "Account not found!" << endl;
}
