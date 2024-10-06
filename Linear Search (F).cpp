#include <iostream>
using namespace std;

void LinearSearch(int arr[],int size, int item) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == item) {
            cout << "Item Found.";
            return;
        }
    }
    cout << "Item Not Found.";
}

int main() {
    int size = 20;
    int arr[size] = {45, 18, 72, 37, 63, 89, 54, 26, 91, 10, 78, 42, 56, 29, 85, 13, 68, 50, 77, 94};

    int value;
    cout<<"Enter The Value You Want To Search : ";
    cin>>value;

    LinearSearch(arr,size,value);

    return 0;
}
