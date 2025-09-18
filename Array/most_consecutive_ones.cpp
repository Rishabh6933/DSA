#include<bits/stdc++.h>
using namespace std;

//Q. find the most consecutive 1's occuring in an array.

int most_consecutive_ones(vector<int> &arr, int n) {
    int count = 0;
    int maxcount = 0;
    for(int i=0 ; i<n; i++) {
        if(arr[i] == 1) {
            count++;
            maxcount = max(count, maxcount);
        }
        else {
            count = 0;
        }
    }
    return maxcount;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<most_consecutive_ones(arr, n);

}