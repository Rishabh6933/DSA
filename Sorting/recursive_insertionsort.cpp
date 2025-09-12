#include<bits/stdc++.h>
using namespace std;

void recursive_insertionsort(int arr[],int i, int n) 
{
    if(i==n)
    return;

    int j=i;
    while(j>0 && arr[j-1]>arr[j]) {
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        j--;
    }

    recursive_insertionsort(arr,i+1, n);
}


int main() 
{

    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];

    recursive_insertionsort(arr, 1, n);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

        

    return 0;
}