#include<bits/stdc++.h>
using namespace std;



vector<int> spiral_matrix(vector<vector<int>> &arr) {
    int row = arr.size();
    int col = arr[0].size();

    int left=0;
    int right = col-1;
    int top = 0;
    int bottom = row-1;

    vector<int> result;

    while(top <= bottom && left <= right) {

        for(int i=left; i<=right; i++) {
            result.push_back(arr[top][i]);
        }
        top++;
        for(int i=top; i<=bottom; i++) {
            result.push_back(arr[i][right]);
        }
        right--;
        if(top <= bottom) {
            for(int i=right; i>=left; i--) {
                result.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if(left <= right) {
            for(int i=bottom; i>=top; i--) {
                result.push_back(arr[i][left]);
            }
            left++;
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

    vector<int> result = spiral_matrix(arr);
    for(auto val : result) {
        cout<<val<<"    \n";
    }

}