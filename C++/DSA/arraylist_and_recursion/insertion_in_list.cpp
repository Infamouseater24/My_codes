#include <iostream>
using namespace std;

void insertABC(int arr[], int &size, int index, int element, int capacity) {
    if (index < 0 || index > size || size >= capacity) {
        cout << "Invalid index or array is full!" << endl;
        return;
    }
    // Shift elements to the right
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the element
    arr[index] = element;
    size++;
}

void printABC(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {10, 20, 30, 40}; // Array with capacity 10
    int size = 4; // Current size
    int index = 2;
    int element = 25;

    cout << "Original Array: ";
    printABC(arr, size);

    insertABC(arr, size, index, element, 10);

    cout << "After Insertion: ";
    printABC(arr, size);

    return 0;
}
