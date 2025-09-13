#include <bits/stdc++.h>
using namespace std;

// Q. Move zeroes to end

void brute_force_movezeroestoend(vector<int> &arr, int n)
{
    int j = 0;
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i < temp.size())
        {
            arr[i] = temp[i];
        }
        else
        {
            arr[i] = 0;
        }
    }
}

void optimal_movezeroestoend(vector<int> &arr, int n)
{
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[j] = arr[i];
            j++;
        }
    }
    for (int i = j; i < n; i++)
    {
        arr[i] = 0;
    }
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

    optimal_movezeroestoend(arr, n);

    brute_force_movezeroestoend(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}