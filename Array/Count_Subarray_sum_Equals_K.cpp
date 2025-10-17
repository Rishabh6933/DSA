#include<bits/stdc++.h>
using namespace std;


// Q. Count the number of Subarray with sum Equals K.

int optimal_Count_Subarray_sum_Equals_K(vector<int> &arr, int num) {
    unordered_map<int, int> mpp;
    int sum = 0;
    int count = 0;
    mpp[0] = 1;
    for(int i=0; i<arr.size(); i++) {
        sum += arr[i];
        int rem = sum - num;
        count += mpp[rem];
        mpp[sum]++; 
    }
    return count;
}


int Bruteforce_Count_Subarray_sum_Equals_K(vector<int> &arr, int num) {
    int count = 0;
    for(int i=0; i<arr.size(); i++) {
        int sum = 0;
        for(int j=i; j<arr.size(); j++) {
            sum += arr[j];
            if(sum == num)
                count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    int k;
    cin>>k;

    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<optimal_Count_Subarray_sum_Equals_K(arr, k);
}