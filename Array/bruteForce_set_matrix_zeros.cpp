#include<bits/stdc++.h>
using namespace std;




void markRow(vector<vector<int>> &arr, int row, int m, int n) {
    for(int j=0; j<n; j++) {
        if(arr[row][j] != 0)
            arr[row][j] = -1;
    }
}

void markCol(vector<vector<int>> &arr, int col, int m, int n) {
    for(int i=0; i<m; i++) {
        if(arr[i][col] != 0)
            arr[i][col] = -1;
    }
}

vector<vector<int>> set_matrix_zeros(vector<vector<int>> &arr) {
    int m = arr.size();
    int n = arr[0].size();
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == 0) {
                markRow(arr, i, m ,n);
                markCol(arr, j, m, n);
            }
        }
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == -1)
                arr[i][j] = 0;
        }
    }
    return arr;
}


int main() {
    int m;
    int n;
    cin>>m;
    cin>>n;

    vector<vector<int>> arr(m, vector<int>(n));

    for(int i = 0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }


    vector<vector<int>> result = set_matrix_zeros(arr);
    for(auto row : result) {
        for(auto val : row) {
            cout<<val<<" ";
        }
        cout<<"\n";
    }
}