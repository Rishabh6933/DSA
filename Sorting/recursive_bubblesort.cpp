#include<bits/stdc++.h>
using namespace std;

void recursive_bubblesort(int arr[], int n) {
    int i;
    if(n==1)
    return;

    for(i=0; i<n-1; i++) {
        if(arr[i]>arr[i+1]) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }

    }
    recursive_bubblesort(arr, n-1);

}

int main() {

    int n;
    cin>>n;
    int arr[n];


    for(int i=0 ; i<n ; i++) {
        cin>>arr[i];
    }

    recursive_bubblesort(arr, n);

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}