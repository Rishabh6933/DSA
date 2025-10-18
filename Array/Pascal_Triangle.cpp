#include<bits/stdc++.h>
using namespace std;

/*
            Pascal Triangle -->
            
                    1
                1       1
            1       2       1
        1       3       3       1
    1       4       6       4       1
1       5       10      10      5       1

*/






// TYPE 1 --> Given row and column. Tell the element at that place

long long pascal_triangle_type11(int row, int col) {
    long long res1=1;
    for(int i=0; i<col; i++) {
        res1 = res1*(row-i);
        res1 = res1/(i+1);
    }
    return res1;
}


int factorial(int n) {
    int res1;
    if(n==1 || n==0) return 1;
    res1 = n*factorial(n-1);
    return res1;
}

int pascal_triangle_type12(int row, int col) {
    int n = factorial(row);
    int d1 = factorial(col);
    int d2 = factorial(row-col);
    int res0 = n/(d1*d2);
    return res0;
}


// TYPE 2 --> Print any Nth row of Pascal Triangle.

vector<int> pascal_triangle_type21(int n) {
    vector<int> res;
    for(int i=1; i<=n; i++) {
        res.push_back(pascal_triangle_type11(n-1, i-1));
    }
    return res;
}


vector<int> pascal_triangle_type22(int n) {
    vector<int> res;
    res.push_back(1);
    long long ans=1;
    for(int i=1; i<n; i++) {
        ans = ans * (n-i);
        ans = ans/(i);
        res.push_back(ans);
    }
    return res;
}


// TYPE 3 --> Print the Pascal Triangle.

vector<int> genRow(int row) {
    vector<int> result;
    int ans = 1;
    result.push_back(ans);
    for(int i=1; i<row; i++) {
        ans = ans * (row-i);
        ans = ans / i;
        result.push_back(ans);
    }
    return result;
}

vector<vector<int>> pascal(int numRows) {
    vector<vector<int>> result;
    for(int i=1; i<=numRows; i++) {
        vector<int> temp = genRow(i);
        result.push_back(temp);
    }
    return result;
}





int main() {
    int row;
    cin>>row;

    vector<vector<int>> result = pascal(row);

    for(auto row : result) {
        for(auto val : row) {
            cout<<val<<" ";
        }
        cout<<"\n";
    }
}