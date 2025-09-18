#include<bits/stdc++.h>
using namespace std;

// Q. Right rotate an array by D place.

vector<int> bruteforce_right_rotate_array_byDplace(vector<int> &arr, int n, int k) {

    k=k%n;
    vector<int> temp(k);
    for(int i=0; i<k; i++) {
        temp[i] = arr[n-k+i];
    }

    for(int i=0 ; i<n-k; i++) {
        arr[n-i-1] = arr[n-k-i-1];
    }

    for(int i=0; i<k; i++) {
        arr[i] = temp[i];
    }
    return arr;
}

void reverse(vector<int> &arr, int start, int end) {

    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

vector<int> optimal_right_rotate_array_byDplace(vector<int> &arr, int n ,int k) {
    
    k=k%n;
    reverse(arr, 0, n-k-1);
    reverse(arr, n-k, n-1);
    reverse(arr, 0, n-1);
    
    return arr;
}



int main() {

    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int k;
    cin>>k;

    //vector<int> result1 = bruteforce_right_rotate_array_byDplace(arr, n, k);
    vector<int> result2 = optimal_right_rotate_array_byDplace(arr, n, k);

    for(int y : result2) {
        cout<<y<<" ";
    }

}