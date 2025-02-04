#include <iostream>
using namespace std;

void deleteABC(int arr[], int &size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index!" << endl;
        return;
    }
    // Shift elements to the left
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
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
    int index = 1;

    cout << "Original Array: ";
    printABC(arr, size);

    deleteABC(arr, size, index);

    cout << "After Deletion: ";
    printABC(arr, size);

    return 0;
}
