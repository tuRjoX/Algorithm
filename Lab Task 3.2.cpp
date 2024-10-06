#include <iostream>
using namespace std;

void merge(int arr[],int l,int m,int r){
    int i=l;
    int j=m+1;
    int k=l;
    int temp[5];

    while(i<=m && m<=j){
        if(arr[i]<=arr[j]){
        temp[k]=arr[i];
        i++;
        k++;
    }else{
        temp[k]=arr[j];
        j++;
        k++;
    }
    }
    
    while(i<=m){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=k){
        temp[k]=arr[j];
        j++;
        k++;
    }

    for(int s=0;s<5;s++){
        arr[s]=temp[s];
    }
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main()
{
    int arr[5] = {5,9,2,3,4};

    cout<<"Before Sorting : ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    mergeSort(arr,0,4);
    cout<<endl;

    cout<<"After Sorting : ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

