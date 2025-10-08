#include<bits/stdc++.h>
using namespace std;

// Q. Maximum subarray sum


int better_maximum_subarray_sum(vector<int> &arr) {
    int maximum = INT_MIN;
    for(int i=0; i<arr.size(); i++) {
        int sum=0;
        for(int j=i; j<arr.size() ; j++) {
            sum += arr[j];
            maximum = max(sum , maximum);
        }
    }
    return maximum;
}

int bruteforce_maximum_subarray_sum(vector<int> &arr) {
    int maximum = INT_MIN;
    for(int i=0; i<arr.size(); i++) {
        for(int j=i; j<arr.size() ; j++) {
            int sum=0;
            for(int k=i; k<j; k++) {
            sum += arr[k];
            maximum = max(sum , maximum);
            }
        }
    }
    return maximum;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<better_maximum_subarray_sum(arr);
    //cout<<bruteforce_maximum_subarray_sum(arr);
}