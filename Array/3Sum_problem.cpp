#include<bits/stdc++.h>
using namespace std;

// Q. To find the triplet in an array that there sum = 0



//OPTIMAL
vector<vector<int>> Optimal_threeSum(vector<int> &arr) {
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++) {
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k) {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(arr[j] == arr[j-1]) j++;
                while(arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}


// BETTER
vector<vector<int>> Better_threeSum(vector<int> &arr) {
    set<vector<int>> st;
    int n = arr.size();
    for(int i=0; i<n-2; i++) {
        set<int> hashSet;
        for(int j=i+1; j<n-1; j++) {
            int third = -(arr[i]+arr[j]);
            hashSet.insert(arr[j]);
            if(hashSet.find(third) != hashSet.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
        }
    }
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}

// BRUTE FORCE
vector<vector<int>> bruteForce_threeSum(vector<int> &arr) {
    set<vector<int>> st;
    int n = arr.size();
    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            for(int k=j+1; k<n; k++) {
                if(arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    vector<vector<int>> result = Optimal_threeSum(arr);
    for(auto row : result) {
        for(auto value : row) {
            cout<<value<<"  ";
        }
        cout<<"\n";
    }


}