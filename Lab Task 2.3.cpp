#include <iostream>
#include <cstdlib>
using namespace std;

int binarySearch(const int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

int main() {
    const int size = 10;
    int arr[size] = {10, 3, 7, 5, 2, 8, 4, 1, 9, 6};

    cout << "Choose a searching procedure:" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;

    int choice;
    cin >> choice;

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    int result = -1;

    switch (choice) {
        case 1:
            insertionSort(arr, size);
            result = binarySearch(arr, size, target);
            break;
        case 2:
            result = linearSearch(arr, size, target);
            break;
        default:
            cerr << "Invalid choice" << endl;
            return EXIT_FAILURE;
    }

    if (result != -1) {
        cout << "Target found at index " << result << endl;
    } else {
        cout << "Target not found in the array" << endl;
    }

    return 0;
}
