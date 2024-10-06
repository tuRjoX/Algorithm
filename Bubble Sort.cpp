#include <iostream>
using namespace std;

void bubbleSort(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main()
{
    int size;
    cout<<"Enter The Size of The Array : ";
    cin>>size;

    int arr[size];
    cout<<"Enter "<<size<<" Integer Number : ";
    for(int i=0 ;i<size;i++)
    cin>>arr[i];

    bubbleSort(arr,size);

    cout<<"Sorted Array Is :";
    for(int i=0 ;i<size;i++)
    cout<<arr[i]<<"  ";

    return 0;
}
