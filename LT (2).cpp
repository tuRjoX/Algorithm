#include<iostream>
using namespace std;

void countSort(int arr[], int n)
{
    int k = arr[0];
    for(int i = 1; i < n; i++)
    {
        k = max(k, arr[i]);
    }

    int count[k + 1] = {0};

    cout<< "Count after each increment"<<endl;
    for(int i = 0; i < n; i++)
    {
        count[arr[i]]++;
        cout << count[arr[i]] << " ";
    }
    cout<<endl;

    cout<< "Next count: "<<endl;
    for(int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
        cout << count[i] << " ";
    }
    cout<<endl;

    cout<<"Decrement:"<<endl;
    int output[n];
    for(int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
        cout << count[arr[i]] << " ";
    }
    cout<<endl;

    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {2, 4, 3, 1, 5};
    int n = 5;
    countSort(arr, n);

    cout<<"Sorted Elements:"<<endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
