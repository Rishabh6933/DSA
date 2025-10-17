#include<bits/stdc++.h>
using namespace std;


/*
        Given an m x n integer matrix matrix, 
        if an element is 0,
        set its entire row and column to 0's.
*/



vector<vector<int>> optimal_set_matrix_zeros(vector<vector<int>> &arr) {
    int m = arr.size();
    int n = arr[0].size();

    // vector<int> row(m,0); --> arr[...][0]
    // vector<int> col(n,0); --> arr[0][...]
    int col0 = 1;


    for(int i=0; i<m ; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == 0) {
                // Mark the ith row
                arr[i][0] = 0;
                // Mark the jth col
                if(j != 0)
                    arr[0][j] = 0;
                else
                    col0 = 0;
                
            }
        }
    }

    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(arr[i][j] != 0) {
                if(arr[i][0] == 0 || arr[0][j] == 0) {
                    arr[i][j] = 0;
                }
            }
        }
    }
    if(arr[0][0] == 0) {
        for(int j=1; j<n; j++)
            arr[0][j] = 0;
    }
    if(col0 == 0) {
        for(int i=0; i<m; i++) {
            arr[i][0] = 0;
        }
    }

return arr;
}


vector<vector<int>> better_set_matirx_zeros(vector<vector<int>> &arr) {
    int m = arr.size();
    int n = arr[0].size();
    vector<int> row(m,0);
    vector<int> col(n,0);

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(row[i] || col[j]) {
                arr[i][j] = 0;
            }
        }
    }
    return arr;
}


int main() {
    int m,n;
    cin>>m;
    cin>>n;
    vector<vector<int>> arr(m,vector<int>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }

    vector<vector<int>> result = optimal_set_matrix_zeros(arr);
    for(auto row : result) {
        for(auto val : row) {
            cout<<val<<"    ";
        }
        cout<<"\n";
    }
}