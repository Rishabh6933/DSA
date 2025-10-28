#include<bits/stdc++.h>
using namespace std;

// Q. To find the Quads in an array that there sum = target(any integer)

//  OPTIMAL
vector<vector<int>> optimal_4sum(vector<int> &arr, int target) {
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i=0; i<n; i++) {
        if(i>0 && arr[i] == arr[i-1]) continue;
        for(int j=i+1; j<n; j++) {
            if(j>i+1 && arr[j] == arr[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k < l) {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if(sum < target) k++;
                else if(sum > target) l--;
                else {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    result.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k] == arr[k-1]) k++;
                    while(k<l && arr[l] == arr[l+1]) l--;
                }
            }

        }
    }       
    return result;
}


//  BETTER
vector<vector<int>> better_4sum(vector<int> &arr, int target) {
    set<vector<int>> st;
    int n = arr.size();
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            set<int> hashSet;
            for(int k=j+1; k<n; k++) {
                long long rem = target - (arr[i] + arr[j] + arr[k]);
                if(hashSet.find(rem) != hashSet.end()) {
                    vector<int> temp = {arr[i], arr[j], arr[k], (int)rem};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}



//  BRUTE FORCE
vector<vector<int>> bruteForce_4sum(vector<int> &arr, int target) {
    int n = arr.size();
    set<vector<int>> st;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                for(int l=k+1; l<n; l++) {
                    long long sum = arr[i];
                    sum += arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if(sum == target) {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;

}






int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    vector<vector<int>> result = optimal_4sum(arr, 0);
    for(auto row : result) {
        for(auto value : row) {
            cout<<value<<"  ";
        }
        cout<<"\n";
    }


}