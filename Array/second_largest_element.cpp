#include<bits/stdc++.h>
using namespace std;

// Q. Find the second largest element in the array.

int optimal_second_largest_element(vector<int> &arr, int n) {
    int largest=arr[0];
    int slargest=INT_MIN;

    for(int i = 1; i<n; i++) {
        if(arr[i]>largest) {
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest) {
            slargest=arr[i];
        }
    }
    return slargest;
}

int second_largest_element(vector<int> &arr, int n) {

    int max=arr[0];
    int secondmax= INT_MIN;

    for(int i=1; i<n; i++) {
        if(arr[i]>max) {
            max=arr[i];
        }
    }

    for(int i=0; i<n; i++) {
        if(arr[i]<max && arr[i]>secondmax) {
            secondmax = arr[i];
        }
    }
    return secondmax;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i =0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<optimal_second_largest_element(arr, n);
    cout<<endl;
    cout<<second_largest_element(arr, n);
}