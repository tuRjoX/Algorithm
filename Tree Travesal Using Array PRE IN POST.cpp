#include<iostream>
using namespace std;

void preOrder(int arr[], int index, int size) {
    if (index < size) {
        cout << arr[index] << " ";
        preOrder(arr, 2 * index + 1, size);
        preOrder(arr, 2 * index + 2, size);
    }
}

void inOrder(int arr[], int index, int size) {
    if (index < size) {
        inOrder(arr, 2 * index + 1, size);
        cout << arr[index] << " ";
        inOrder(arr, 2 * index + 2, size);
    }
}

void postOrder(int arr[], int index, int size) {
    if (index < size) {
        postOrder(arr, 2 * index + 1, size);
        postOrder(arr, 2 * index + 2, size);
        cout << arr[index] << " ";
    }
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Pre-order traversal: ";
    preOrder(arr, 0, 10);
    cout << endl;

    cout << "In-order traversal: ";
    inOrder(arr, 0, 10);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrder(arr, 0, 10);
    cout << endl;

    return 0;
}
