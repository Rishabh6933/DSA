#include<bits/stdc++.h>
using namespace std;

bool palindrome(int i, int n, string array[]) {
    if(i>=n/2)
    return true;
    if(array[i]!=array[n-i-1])
    return false;
    return palindrome(i+1,n , array);
}

int main() {
    int i,n;
    cin>>n;
    string array[n];
    for(i=0;i<n;i++) {
        cin>>array[i];
    }
    cout<<boolalpha<<palindrome(0,n,array);
}