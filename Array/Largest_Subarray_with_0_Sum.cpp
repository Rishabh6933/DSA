#include<bits/stdc++.h>
using namespace std;


/*
    Given an array containing both positive and negative integers, 
    we have to find the length of the longest subarray 
    with the sum of all elements equal to zero.
*/

	
int Largest_Subarray_with_0_Sum(vector<int> &arr) {
    int n = arr.size();
    int sum = 0;
    int maxi = 0;
    unordered_map<int, int> mpp;
    for(int i=0; i<n ; i++) {
        sum += arr[i];
        if(sum == 0) 
            maxi = i+1;
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i-mpp[sum]);
            }
            else {
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}



int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int result = Largest_Subarray_with_0_Sum(arr);
    cout<<result;
}