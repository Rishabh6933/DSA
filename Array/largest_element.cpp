#include<bits/stdc++.h>
using namespace std;

// Q. Find the largest element in the array.

int largest_element(vector<int> &arr, int n) {
    int max=INT_MIN;
    for(int i=1; i<n; i++) {
        if(arr[i]>max) {
            max=arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<largest_element(arr, n);


}