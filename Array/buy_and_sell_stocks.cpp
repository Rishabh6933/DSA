#include<bits/stdc++.h>
using namespace std;

// Best time to buy and sell stocks

int buy_and_sell_stocks(vector<int> &arr) {
    int buy = arr[0];
    int profit = 0;
    for(int i=1 ; i<arr.size() ; i++) {
        int sell = arr[i];
        profit = max(profit, sell-buy);
        buy = min(buy, arr[i]);
    }
    return profit;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<buy_and_sell_stocks(arr);
}