#include<bits/stdc++.h>
using namespace std;

// Q. Find the just next greater element formed using the array element.

/*
        2   "1"   5     4     3     0     0  
            small <------------------------- 
                            increasing
            
    "1" is the element which has to be changed

    find the element from the right of 1 which is just 
    greater than the 1 or we can say smallest among all the 
    elements in the right side of 1 i.e "3"

    swap 1 and 3

        2   "3"     5    4    1     0      0

    now make the right side of "3" smallest by putting the right side elements in such
    a way that they make up smallest number i.e  0  0   1   4   5
    this can be done by just reversing the elements right to 3.

                    2   3   0   0   1   4   5

               <--------this is the answer-------->                    
*/


vector<int> next_permutation(vector<int> &arr) {
    int index = -1;
    int n = arr.size();

    for(int i=n-2; i>=0; i--) {
        if(arr[i] < arr[i+1]) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for(int i=n-1; i>=0; i--) {
        if(arr[i] > arr[index]) {
            swap(arr[index], arr[i]);
            break;
        }
    }
    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}


int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    vector<int> result = next_permutation(arr);
    for(int x : result) {
        cout<<x<<"  ";
    }
}