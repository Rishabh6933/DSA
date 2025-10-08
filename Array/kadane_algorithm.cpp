#include<bits/stdc++.h>
using namespace std;

/*
        Q. Maximum subarray sum

        THIS IS KADANE'S ALGORITHM
*/



// This is for printing the complete subarray
vector<int> kadane(vector<int> &arr) {
    vector<int> result;
    int maximum = INT_MIN;
    int sum=0;
    int start = 0;
    int ansStart = 0;
    int ansEnd = 0;
    for(int i=0; i<arr.size(); i++) {
        sum += arr[i];
        if(sum > maximum) {
            maximum = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0) {
            sum = 0;
            start = i+1;
        }
    }
    for (int i = ansStart; i <= ansEnd; i++) {
        result.push_back(arr[i]);
    }
    return result;
}


// This is for just printing the maximum sum of the subarray
int kadane_algo(vector<int> &arr) {
    int maximum = INT_MIN;
    int sum=0;
    for(int i=0; i<arr.size(); i++) {
        sum += arr[i];
        maximum = max(sum, maximum);
        if(sum < 0)
            sum = 0;
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

    cout<<kadane_algo(arr);
    cout<<"\n";
    vector<int> result = kadane(arr);
    for(int y : result) {
        cout<<y<<"  ";
    }
    // vector<int> result = kadane_algo(arr);
    // for(int x:result) {
    //     cout<<x<<"  ";
    // }
    
}