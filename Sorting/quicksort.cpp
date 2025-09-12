#include<bits/stdc++.h>
using namespace std;
//using Lomuto partition

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<high; j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;

}

void quick_sort(vector<int> &arr , int low, int high)
{
    if(low<high)
    {
    int pIndex = partition(arr, low, high);
    quick_sort(arr, low, pIndex-1);
    quick_sort(arr, pIndex+1, high);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++)
        cin>>arr[i];

    quick_sort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";


}