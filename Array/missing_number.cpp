#include<bits/stdc++.h>
using namespace std;

// Q. Find the missing number in an array (array is from 1-->N).

int optimal_missingnumber(vector<int> &arr, int n) {
    int xor1=0;
    int xor2 = 0;
    for(int i=0; i<arr.size(); i++) {
        xor1 = xor1^arr[i];
        xor2 = xor2^i+1;
    }
    xor1 = xor1^n;
    return xor1^xor2;
}

int optimal_missing_number(vector<int> &arr, int n) {
    int sum = (n*(n+1))/2;
    int arrsum = 0;
    for(int i=0 ; i<arr.size(); i++) {
        arrsum = arrsum + arr[i];
    }

    return (sum - arrsum);
}

int better_missing_number(vector<int> &arr, int n) {
    int hash[n+1] = {0};
    for(int i=0; i<arr.size(); i++) {
        hash[arr[i]] = 1;
    }
    for(int i=1 ; i<=n; i++) {
        if(hash[i] == 0)
            return i;
        }
}


int bruteforce_missing_number(vector<int> &arr, int n) {
    int i,j;
    for(i=1; i<n; i++) {
        int flag = 0;
        for(j = 0; j<arr.size() ; j++) {
            if(arr[j] == i) {
                flag=1;
                break;
            }
        }
        if(flag == 0)
            return i;    
    }
    return 0;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n-1);

    for(int i=0; i<n-1; i++) {
        cin>>arr[i];
    }

    cout<<optimal_missingnumber(arr, n);
    //cout<<optimal_missing_number(arr, n);
    //cout<<better_missing_number(arr, n);
    //cout<<bruteforce_missing_number(arr, n);

}