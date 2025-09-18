#include<bits/stdc++.h>
using namespace std;

// Q. Find the element that appears only once in the array and rest of the element appears only once.

int bruteforce_element_that_appear_once(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) {
        int count=0;
        int num = arr[i];
        for(int j=0 ; j<arr.size(); j++) {
            if(arr[j] == arr[i])
                count++;
        }
        if(count==1)
            return num;
    }
    return 0;
}

int better_element_that_appear_once(vector<int> &arr) {
    int maximum=arr[0];
    for(int i = 0; i<arr.size() ; i++) {
        maximum = max(arr[i] , maximum);
    }
    int hash[maximum+1] = {0};

    for(int i=0; i<arr.size(); i++) {
        hash[arr[i]]++;
    }
    for(int i=0; i<=arr.size(); i++) {
        if(hash[arr[i]] == 1)
            return arr[i];
    }
    return 0;
}

int optimal_element_that_appear_once(vector<int> &arr) {
    int result=0;
    for(int i=0; i<arr.size(); i++) {
        result=result^arr[i];
    }
    return result;
}


int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<optimal_element_that_appear_once(arr);
    //cout<<better_element_that_appear_once(arr);
    //cout<<bruteforce_element_that_appear_once(arr);

}