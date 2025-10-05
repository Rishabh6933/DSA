#include<bits/stdc++.h>
using namespace std;


/*
    Q.  Two Sum problem
        i)  return true if such pair exist whose sum is equal to the number asked.
        ii) return the index of those two numbers whose sum is equal to the number asked.

*/

vector<int> optimal_twosum(vector<int> &arr, int target) {
    vector<int> copyArr = arr;
    sort(copyArr.begin(), copyArr.end());
    int left = 0;
    int right = arr.size()-1;
    while(left < right) {
        if(arr[left] + arr[right] == target)
            return {left, right};
        else if(arr[left] + arr[right] < target)
            left++;
        else
            right--;
    }
    return {};
}

vector<int> better_twosum(vector<int> &arr, int target) {
    map<int, int> mpp;
    for(int i=0 ; i<arr.size(); i++) {
        int a = arr[i];
        int more = target - a;
        if(mpp.find(more) != mpp.end())
            return {mpp[more], i};
        mpp[a] = i;
    }
    return {};
}


vector<int> bruteforcee_twoSum(vector<int> &arr, int target) {
    for(int i=0; i<arr.size()-1; i++) {
        for(int j=i+1; j<arr.size(); j++) {
            if(arr[i] + arr[j] == target)
                //return true;
                return {i,j};
        }
    }
    return {};
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    int targetSum;
    cin>>targetSum;


    vector<int> result = optimal_twosum(arr, targetSum);
    //vector<int> result = better_twosum(arr, targetSum);
    //vector<int> result = bruteforcee_twoSum(arr, targetSum);
    cout<<result[0]<<"  "<<result[1];
}