#include<bits/stdc++.h>
using namespace std;

// Q. Remove the duplicate elements from a sorted array.

int remove_duplicacy(vector<int> &arr, int n) {
    int i=0;
    for(int j=1; j<n; j++) {

        if(arr[i] != arr[j]) {
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    int x = remove_duplicacy(arr, n);

    for(int i=0; i<=x; i++) {
        cout<<arr[i]<<" ";
    }
    
}