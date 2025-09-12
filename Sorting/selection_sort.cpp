#include<bits/stdc++.h>
using namespace std;


void selection_sort(int arr[], int n) {
        for(int i=0; i<n-1; i++) {
        int min=i;
        for(int j=i+1; j<n; j++) {

            if(arr[min]>arr[j]) {
                min=j;


            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }

    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++ ) {
        cin>>arr[i];
    }

    selection_sort(arr,n);

    cout<<"The sorted array is : \n";
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<"\t";
    }

}