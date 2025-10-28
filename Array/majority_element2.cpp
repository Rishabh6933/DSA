#include<bits/stdc++.h>
using namespace std;


// Q. Check in the array that an element is present more than n/3 times in the array

vector<int> optimal_majority_element(vector<int> &arr) {
    vector<int> result;
    int n = arr.size();
    int count1=0, count2=0;
    int element1, element2;

    for(int i=0; i<n; i++) {
        if(count1 == 0 && arr[i] != element2) {
            element1 = arr[i];
            count1++;
        }
        else if(count2 == 0 && arr[i] != element1) {
            element2 = arr[i]; 
            count2++;
        }
        else if(arr[i] == element1)     count1++;
        else if(arr[i] == element2)     count2++;
        else {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for(int i=0; i<n; i++) {
        if(element1 == arr[i]) count1++;
        else if(element2 == arr[i]) count2++;
    }

    if(count1 > n/3)    result.push_back(element1);
    if(count2 > n/3)    result.push_back(element2);

    return result;
}


vector<int> better_majority_element(vector<int> &arr) {
    vector<int> result;
    int n = arr.size();
    int minVal = (n/3)+1;
    unordered_map<int, int> mpp;
    for(int i=0; i < n; i++) {
        mpp[arr[i]]++;
        if(mpp[arr[i]] == minVal)
            result.push_back(arr[i]);
        if(result.size() == 2)
            break;
    }
    return result;
}

vector<int> bruteforce_majority_element(vector<int> &arr) {
    vector<int> result;
    int n = arr.size();
    
    for(int i=0; i<n; i++) {
        if(result.size() == 0 || result[0] != arr[i]) {
            int count=0;
            for(int j=0; j<n; j++) {
                if(arr[i] == arr[j])
                    count++;
            }
            if(count > n/3)
                result.push_back(arr[i]);
            if(result.size() == 2)
                break;
        }
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

    vector<int> result = better_majority_element(arr);
    for(auto it : result) {
        cout<<it<<" ";
    }
}