#include<bits/stdc++.h>
using namespace std;

// Q. Find the size of longest subarray with given sum


// only for positives
int optimal_longest_subarray_with_given_sum(vector<int> &arr, int num)
{
    int sum=0;
    int i=0;
    int len = 0;
    for(int j=0; j<arr.size(); j++)
    {
        sum += arr[j];
        while(sum > num)
        {
            sum -= arr[i];
            i++;
        }
        if(sum == num)
            len = max(len,j-i+1);
    }
    return len;
}



// for both positives and negatives
int better_longest_subarray_with_given_sum(vector<int> &arr, int num) {

    map<long long, int> PreSumMap;
    long long sum=0;
    int MaxLen=0;
    for(int i=0; i<arr.size(); i++) {
            sum += arr[i];
            if(sum == num)
                MaxLen = max(MaxLen, i+1);

            long long rem = sum - num;
            if(PreSumMap.find(rem) != PreSumMap.end()) {
                int len = i - PreSumMap[rem];
                MaxLen = max(MaxLen , len);
            }
            if (PreSumMap.find(sum) == PreSumMap.end())
                PreSumMap[sum] = i;
    }
    return MaxLen;
}

int bruteforce_optimised_longest_subarray_with_given_sum(vector<int> &arr, int num) {
    int len=0;
    for(int i=0; i<arr.size(); i++) {
        int sum=0;
        for(int j=i; j<arr.size(); j++) {
            sum += arr[j];
            if(sum == num)
                len = max(len, j-i+1);
        }
    }
    return len;
}

int buteforce_longest_subarray_with_given_sum(vector<int> &arr, int num) {
    int len=0;
    for(int i=0; i<arr.size(); i++) {
        for(int j=i; j<arr.size(); j++) {
            int sum=0;
            for(int k=i; k<=j; k++)
                sum += arr[k];
            if(sum == num)
                len = max(len, j-i+1);
        }
    }
    return len;
}

int main() {
    int n,num;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cin>>num;

    cout<<optimal_longest_subarray_with_given_sum(arr,num);
    //cout<<better_longest_subarray_with_given_sum(arr,num);
    //cout<<bruteforce_optimised_longest_subarray_with_given_sum(arr,num);
    //cout<<buteforce_longest_subarray_with_given_sum(arr, num);

}