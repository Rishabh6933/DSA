#include <bits/stdc++.h>
using namespace std;


// Q. Linear Search

int linear_search(vector<int> &arr, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int x, n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    cout << linear_search(arr, n, x);
    return 0;
}