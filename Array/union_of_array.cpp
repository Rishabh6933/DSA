#include<bits/stdc++.h>
using namespace std;

// Q. Union of two sorted arrays

vector<int> unionArray(vector<int> &arr1, int n, vector<int> &arr2, int m) {

    vector<int> unionArr;
    int i=0;
    int j=0;

    while(i<n && j<m) {
        if(arr1[i]<arr2[j]) {
            if(unionArr.size() == 0 || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }

        else if(arr2[j] < arr1[i]){
            if(unionArr.size() == 0 || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }

        else {
            if(unionArr.size() == 0 || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    while(i<n) {
        if(unionArr.size() == 0 || unionArr.back() != arr1[i]) {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    while(j<m) {
        if(unionArr.size() == 0 || unionArr.back() != arr2[j]) {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }
    return unionArr;

}



// union of two unsorted arrays

vector<int> unionArr(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    set<int> s;
    for(int i=0; i<arr1.size(); i++) {
        s.insert(arr1[i]);
    }
    for(int i=0; i<arr2.size(); i++) {
        s.insert(arr2[i]);
    }
    vector<int> unionArr(s.begin(), s.end());
    return unionArr;
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

    vector<int> result = unionArr(arr1, n, arr2, m);

    for(int x : result) {
        cout<<x<<" ";
    }

}