#include <iostream>

using namespace std;

void insertInMiddle(int arr[], int& size, int newItem) {
    int middle = size / 2;

    for (int i = size; i > middle; i--) {
        arr[i] = arr[i - 1];
    }

    arr[middle] = newItem;

    size++;
}

int main() {
    int arr[100];
    int size;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    // Input elements of the array
    cout << "Enter " << size << " elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int newItem;
    cout << "Enter the new item to insert: ";
    cin >> newItem;

    insertInMiddle(arr, size, newItem);

    cout << "Array after insertion: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
