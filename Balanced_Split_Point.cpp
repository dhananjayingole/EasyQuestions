// 1. Arrays — "Balanced Split Point"
// Given an integer array, find an index i such that the sum of elements to the left of i equals the sum of
// elements to the right of i (element at i itself is excluded). Return the smallest such index, or -1 if none exists.
// Input: [1, 7, 3, 6, 5, 6]
// Output: 3 (left sum = 1+7+3=11, right sum = 5+6=11)

#include<bits/stdc++.h>
using namespace std;

int findPivotIndex(vector<int>&nums){
    int n = nums.size();
    int total_sum = 0;
    for(int num: nums){
        total_sum += num;
    }

    int left_sum = 0;
    for(int i=0;i<n;i++){
        if(left_sum == total_sum -left_sum - nums[i]){
            return i;
        }
        left_sum += nums[i];
    }
    return -1;
}

int main(){

    vector<int>nums = {1, 7, 3, 6, 5, 6};

    int ans = findPivotIndex(nums);

    cout<<ans<<endl;

    return 0;
}
