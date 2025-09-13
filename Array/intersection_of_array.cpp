#include<bits/stdc++.h>
using namespace std;

vector<int> intersectionArray(vector<int> &arr1, int n, vector<int> &arr2, int m) {




    
}

int main() {
    int n;
    cin>>n;
    vector<int> arr1(n);

    for(int i=0 ; i<n ; i++) {
        cin>>arr1[i];
    }

    int m;
    cin>>m;
    vector<int> arr2(m);

    for(int i=0; i<m ; i++) {
        cin>>arr2[i];
    }

    vector<int> result = intersectionArray(arr1, n, arr2, m);

    for(int x : result) {
        cout<<x<<" ";
    }

}