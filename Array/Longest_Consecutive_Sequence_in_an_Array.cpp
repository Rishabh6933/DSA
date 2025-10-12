#include<bits/stdc++.h>
using namespace std;

int optimal_Longest_Consecutive_Sequence_in_an_Array(vector<int> &arr) {
    if(arr.size() == 0)
        return 0;
    int longest = 1;
    unordered_set<int> st;
    for(int i=0; i<arr.size(); i++) {
        st.insert(arr[i]);
    }

    for(auto it : st) {
        int cnt = 1;
        int x = it;
        if(st.find(it - 1) == st.end()) {
            while(st.find(x+1) != st.end()) {
                cnt++;
                x++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int better_Longest_Consecutive_Sequence_in_an_Array(vector<int> &arr) {
    if(arr.size() == 0)
        return 0;
    sort(arr.begin(), arr.end());
    int lastSmaller = arr[0];
    int longest = 1;
    int count = 1;
    for(int i=1 ; i<arr.size(); i++) {
        if(arr[i] - 1 == lastSmaller) {
            count++;
            lastSmaller = arr[i];
        }
        else if(arr[i] != lastSmaller) {
            count = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, count);
    }
    return longest;
}

bool linear_search(vector<int> &arr, int x) {
    for(int i=0; i<arr.size(); i++) {
        if(x == arr[i])
            return true;
    }
    return false;
}

int bruteforce_Longest_Consecutive_Sequence_in_an_Array(vector<int> &arr) {
    int longest = 1;
    for(int i=0; i<arr.size()-1; i++) {
        int x=arr[i];
        int count=1;
        while(linear_search(arr, x+1)) {
            x++;
            count++;
        }
        longest = max(longest, count);
    }
    return longest;
} 

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<better_Longest_Consecutive_Sequence_in_an_Array(arr);

    //cout<<bruteforce_Longest_Consecutive_Sequence_in_an_Array(arr);
}