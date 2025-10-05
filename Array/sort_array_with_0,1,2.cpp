#include <bits/stdc++.h>
using namespace std;

// Q. Sort an array containing only 0, 1 and 2.

vector<int> sort_array(vector<int> &arr)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    for (int i = 0; i < count0; i++)
        arr[i] = 0;
    for (int i = count0; i < count0 + count1; i++)
        arr[i] = 1;
    for (int i = count0 + count1; i < arr.size(); i++)
        arr[i] = 2;

        return arr;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = sort_array(arr);
    for(int x : result)
        cout<<x<<"  ";
}