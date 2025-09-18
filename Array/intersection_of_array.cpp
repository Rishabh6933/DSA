#include<bits/stdc++.h>
using namespace std;

// Q. Find intersection of two sorted arrays 

vector<int> optimal_intersectionArray(vector<int> &arr1, int n, vector<int> &arr2, int m) {


    vector<int> ans;
    int i=0,j=0;

    while(i<n && j<m) {
        if(arr1[i] < arr2[j])
            i++;

        else if(arr2[j] < arr1[i])
            j++;

        else {
            if(ans.empty() || ans.back() != arr1[i]) {
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }
    return ans;
}


vector<int> bruteforce_intersectionArray(vector<int> &arr1, int n, vector<int> &arr2, int m) {

    vector<int> ans;
    int i,j;
    int vis[m] = {0};

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(arr1[i] == arr2[j] && vis[j]==0)
            {
                ans.push_back(arr1[i]);
                vis[j] = 1;
                break;
            }
            if(arr2[j]>arr1[i])
                break;
        }
    }

    return ans;    
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

    //vector<int> result1 = bruteforce_intersectionArray(arr1, n, arr2, m);

    vector<int> result2 = optimal_intersectionArray(arr1, n, arr2, m);



    for(int x : result2) {
        cout<<x<<" ";
    }

}