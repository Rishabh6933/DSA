#include<bits/stdc++.h>
using namespace std;

// Q. Find the majority element (more than n/2 times)

int moore_voting_algo(vector<int> &arr) {
    int count=0;
    int element;
    for(int i =0; i<arr.size(); i++) {
        if(count == 0) {
            element = arr[i];
            count++;
        }
        else if(element == arr[i])
            count++;
        else
            count--;
    }
    int cnt=0;
    for(int i=0 ; i<arr.size(); i++) {
        if(arr[i] == element)
            cnt++;
        if(cnt > arr.size()/2)
            return element;
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

    cout<<moore_voting_algo(arr);
}