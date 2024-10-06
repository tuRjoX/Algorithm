#include <iostream>

using namespace std;

int main()
{
    int arr[5];
    cout<<"Enter 5 Integer Number : ";
    for(int i=0 ;i<5;i++)
    cin>>arr[i];

    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }

    cout<<"Sorted Array Is :";
    for(int i=0 ;i<5;i++)
    cout<<arr[i]<<"  ";

    return 0;
}
