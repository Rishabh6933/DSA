#include<bits/stdc++.h>
using namespace std;

/*
Find the leaders in an array i.e.
     everything to the right of any element in an array
     must be smaller than that element
*/

vector<int> optimal_leaders_in_an_array(vector<int> &arr) {
    vector<int> leaders;
    int n =arr.size();
    int maximum = INT_MIN;
    for(int i=n-1 ; i>=0 ; i--) {
        if(arr[i] > maximum) {
            leaders.push_back(arr[i]);
            maximum = arr[i];
        }
    }
    return leaders;
}


vector<int> bruteforoce_leaders_in_an_array(vector<int> &arr) {
    vector<int> leaders;
    int n = arr.size();
    for(int i=0; i<n; i++) {
        bool leader = true;
        for(int j=i+1; j<n; j++) {
            if(arr[j] > arr[i]) {
                leader = false;
                break;
            }
        }
        if(leader)
            leaders.push_back(arr[i]);
    }
    return leaders;
}


int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    vector<int> result = optimal_leaders_in_an_array(arr);
    for(int x: result) {
        cout<<x<<"  ";
    }
}