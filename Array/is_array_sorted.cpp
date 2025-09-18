#include<bits/stdc++.h>
using namespace std;


// Q. Check if the given array is sorted or not?


bool is_array_sorted(vector<int> &arr, int n) {
    for(int i=0; i<n-1; i++) {
        if(arr[i]>arr[i+1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<boolalpha<<is_array_sorted(arr, n);
}