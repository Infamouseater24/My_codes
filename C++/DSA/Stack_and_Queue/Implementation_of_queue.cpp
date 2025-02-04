#include <iostream>
using namespace std;

class Queue {
    int *queue, front, rear, size;

public:
    Queue(int x) : size(x), front(-1), rear(-1) { queue = new int[size]; }
    ~Queue() { delete[] queue; }
    void enqueue(int value) {
        if (rear == size - 1) cout << "Overflow!\n";
        else {
            if (front == -1) front = 0;
            queue[++rear] = value;
            cout << "Enqueued: " << value << endl;
        }
    }
    void dequeue() {
        if (front == -1 || front > rear) cout << "Underflow!\n"; 
        else {
            cout << "Dequeued: " << queues[front++] << endl;
            if (front > rear) { 
                front = rear = -1;
            }
        }
    }
    void display() {
        if (front == -1) cout << "Queue is empty!\n";
        else {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size, choice, value;
    cout << "Enter size of queue: ";
    cin >> size;
    Queue q(size);

    do {
        cout << "\n1. Enqueue  2. Dequeue  3. Display  4. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) { 
            cout << "Value: "; 
            cin >> value; 
            q.enqueue(value); 
        }
        else if (choice == 2) q.dequeue();
        else if (choice == 3) q.display();
    } while (choice != 4);

    return 0;
}
