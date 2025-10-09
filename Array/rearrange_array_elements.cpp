#include<bits/stdc++.h>
using namespace std;

// Q. Rearrange the array elements
//  1st variety --> equal number of positive and negative integer are present in the array

vector<int> optimal_rearrange_array_elements(vector<int> &arr) {
    vector<int> result;
    int pkey=0;
    int nkey=1;
    for(int i=0; i<arr.size() ; i++) {
        if(arr[i] >= 0) {
            result[pkey] = arr[i];
            pkey += 2;
        }
        else {
            result[nkey] = arr[i];
            nkey += 2;
        }
    }
    return result;
}

vector<int> bruteforce_rearrange_array_elements(vector<int> &arr) {
    vector<int> pos;
    vector<int> neg;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }
    for(int i=0; i<pos.size(); i++) {
        arr[2*i] = pos[i];
        arr[2*i + 1] = neg[i];
    }
    return arr;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    vector<int> result = rearrange_array_elements(arr);

    for(int x : result) {
        cout<<x<<"  ";
    }
}

//  2nd variety --> poitive and negative integers are not equal in numbers

vector<int> rearrange_array_elements(vector<int> &arr) {
    vector<int> pos;
    vector<int> neg;

    for(int i=0; i<arr.size(); i++) {
        if(arr[i] > 0) 
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }
    
    if(pos.size() > neg.size()) {
        for(int i=0 ; i<neg.size(); i++) {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = neg.size()*2;
        for(int i=neg.size(); i<pos.size() ; i++) {
            arr[index] = pos[i];
            index++;
        }
    }
    else {
        for(int i=0 ; i<pos.size(); i++) {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = pos.size()*2;
        for(int i=pos.size(); i<neg.size() ; i++) {
            arr[index] = neg[i];
            index++;
        }
    }
    return arr;
}

