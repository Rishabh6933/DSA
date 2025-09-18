#include<bits/stdc++.h>
using namespace std;

// Q. Left rotate an array by D place.

vector<int> bruteforce_left_rotate_array_byDplace(vector<int> &arr, int n, int k) {

    k=k%n;
    vector<int> temp(k);

    for(int i=0; i<k; i++) {
        temp[i] = arr[i];
    }

    for(int i=0; i<n-k; i++) {
        arr[i] = arr[i+k];
    }

    for(int i=n-k;i<n;i++) {
        arr[i] = temp[i-n+k];
    }
    return arr;

}


void reverse(vector<int> &arr, int start, int end) {

    while(start<end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }


}

vector<int> optimal_left_rotate_array_byDplace(vector<int> &arr, int n ,int k) {
// in this method just reverse the array
    k=k%n;
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);
    reverse(arr, 0, n-1);

    return arr;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    int k;
    cin>>k;

    //vector<int> result1 = bruteforce_left_rotate_array_byDplace(arr, n, k);
    vector<int> result2 = optimal_left_rotate_array_byDplace(arr, n ,k);

    for(int y : result2) {
        cout<<y<<" ";
    }
}