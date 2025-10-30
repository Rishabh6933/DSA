#include<bits/stdc++.h>
using namespace std;

/*
        Given an array of integers A and an integer B.
        Find the total number of subarrays having bitwise XOR
        of all elements equal to k.
*/


// Take reference from ----> Count_Subarray_sum_Equals_K
int Count_number_of_subarrays_with_given_xor_K(vector<int> &arr, int k) {
    unordered_map<int, int> mpp;
    int n = arr.size();
    int count = 0;
    int preXOR = 0;
    mpp[preXOR]++; 
    for(int i=0; i<n; i++) {
        preXOR = preXOR xor arr[i];
        int x = preXOR xor k;
        count += mpp[x];
        mpp[preXOR]++;
    }
    return count;
}

int diffMethod(vector<int> &arr, int k) {
    unordered_map<int, int> mpp;
    int n = arr.size();
    int count = 0;
    int preXOR = 0;
    for(int i=0; i<n; i++) {
        preXOR = preXOR xor arr[i];
        int x = preXOR xor k;
        if(preXOR == k) count++;
        else if(mpp.find(x) != mpp.end()) count += mpp[x];
        mpp[preXOR]++;
    }
    return count;
}



int main() {
    int n;
    cin>>n;
    int k;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cin>>k;
    int result = diffMethod(arr, k);
    cout<<result;
}