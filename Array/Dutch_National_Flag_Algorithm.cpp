#include<bits/stdc++.h>
using namespace std;


// Q. Sort an array containing only 0, 1 and 2.
/*  
        THIS IS DUTCH NATIONAL FLAG ALGROITHM
        TIME COMPLEXITY = O(n)
        SPACE COMPLEXITY = O(1)
*/


vector<int> dutch_algo(vector<int> &arr) {
    int low=0;
    int mid=0;
    int high=arr.size()-1;

    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
            mid++;
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    return arr;
}


int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    vector<int> result = dutch_algo(arr);
    for(int x : result)
        cout<<x<<"  ";
}