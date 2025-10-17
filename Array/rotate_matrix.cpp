#include<bits/stdc++.h>
using namespace std;

/*
    Q. Rotate the Matrix clockwise by 90 deg
*/



vector<vector<int>> optimal_rotate_matrix(vector<vector<int>> &arr) {
    int m = arr.size();
    int n = arr[0].size();


    // Transpose of Matrix
    for(int i=0; i<m-1; i++) {
        for(int j=i+1; j<n; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // Reverse the rows
    for(int i=0; i<m; i++) {
        reverse(arr[i].begin(), arr[i].end());
    }
 
    // for(auto &row : arr) {
    //     reverse(row.begin(), row.end());
    // }

    return arr;
}


vector<vector<int>> bruteForce_rotate_matrix(vector<vector<int>> &arr) {
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<int>> result(n, vector<int>(m));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            result[j][m-i-1] = arr[i][j];
        }
    }
    return result;
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

    vector<vector<int>> result = optimal_rotate_matrix(arr);
    for(auto row : result) {
        for(auto val : row) {
            cout<<val<<"    ";
        }
        cout<<"\n";
    }
}