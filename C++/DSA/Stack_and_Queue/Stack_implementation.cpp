#include <iostream>
using namespace std;

class Stack {
private:
    char stack[100];
    int top;

public:
    Stack() : top(-1) {}

    void push(char c) {
            top++;
            stack[top] = c;
            cout << "push success" << endl;
    }

    void pop() {
        if (top >= 0) {
            top--;
            cout << "pop success" << endl;
        } else {
            cout << "Stack underflow!" << endl;
        }
    }
    void display() {
        for(int i = top; i >= 0; i--){
            cout << stack[i];
        }
        cout << endl;
    }
};

int main() {
    Stack st;
    st.push('A');
    st.push('B');
    st.push('C');
    st.display();
    st.pop();
    st.display();
    st.push('D');
    st.display();
    st.pop();
    st.display();
    st.pop();
    st.display();
    st.pop();
    st.display();
    st.pop();
    return 0;
}
