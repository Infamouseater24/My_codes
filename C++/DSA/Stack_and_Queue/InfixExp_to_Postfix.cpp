#include <iostream>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    else
        return false;
}

class Stack {
private:
    char stack[100];
    int top;

public:
    Stack() : top(-1) {}

    void push(char c) {
        if (top < 99) {
            stack[++top] = c;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    char pop() {
        if (top >= 0) {
            return stack[top--];
        } else {
            cout << "Stack underflow!" << endl;
            return '\0';
        }
    }

    char peek() {
        if (top >= 0) {
            return stack[top];
        } else {
            return '\0';
        }
    }

    bool isEmpty() {
        if(top == -1){
            return true;
        }
        else {
            return false;
        }
    }
};

string infixToPostfix(const string& infix) {
    Stack st; 
    string postfix = ""; 

    for (char ch : infix) {
        if (isalnum(ch)) { 
            postfix += ch;
        } else if (ch == '(') { 
            st.push(ch);
        } else if (ch == ')') { 
            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
            }
            if (!st.isEmpty() && st.peek() == '(') {
                st.pop();
            }
        } else if (isOperator(ch)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(ch)) {
                postfix += st.pop();
            }
            st.push(ch);
        }
    }



    while (!st.isEmpty()) {
        postfix += st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
