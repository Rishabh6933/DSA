#include<bits/stdc++.h>
using namespace std;

// Q. Find the majority element (more than n/2 times)

int better_majority_element(vector<int> &arr) {
    map<int, int> mpp;
    for(int i=0 ; i<arr.size() ; i++) {
        mpp[arr[i]]++;
    }
    for (auto &it : mpp) {
        if (it.second > arr.size() / 2)
            return it.first;
    }
    return -1;
}

int bruteForce_majority_element(vector<int> &arr) {
    for(int i=0 ; i<arr.size() ; i++) {
        int count = 1;
        for(int j=1 ; j<arr.size() ; j++) {
            if(arr[i] == arr[j])
                count++;
        }
        if(count > arr.size()/2)
            return arr[i];
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }    
    cout<<better_majority_element(arr);
    // cout<<bruteForce_majority_element(arr);
}