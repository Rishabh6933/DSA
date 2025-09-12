#include<bits/stdc++.h>
using namespace std;

int funct(int n) {
    if(n<=1)
    return n;
    int last=funct(n-1);
    int slast=funct(n-2);
    return last+slast;
}

int main() {
    int n;
    cin>>n;
    cout<<funct(n);
    return 0;
}