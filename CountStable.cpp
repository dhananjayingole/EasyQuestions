// Problem 1: Stable Window

// Given an array arr of n readings and an integer k, count the subarrays of length exactly k where (maximum − minimum) ≤ d.

// Function: long long countStable(vector<int> arr, int k, int d)

// Constraints: 1 ≤ n ≤ 10^6, 1 ≤ k ≤ n, 1 ≤ arr[i] ≤ 10^9, 0 ≤ d ≤ 10^9

// Sample: arr = [1, 3, 2, 6, 4, 5], k = 3, d = 2
// Output: 2
// Valid windows: [1,3,2] and [6,4,5].

  
#include <bits/stdc++.h>
using namespace std;

long long countStable(vector<int> nums, int k, int d) {
    int n = nums.size();
    long long cnt = 0;

    int left = 0;
    for (int right = 0; right < n; right++) {
        if (right - left + 1 == k) {
            int maxi = *max_element(nums.begin() + left, nums.begin() + right + 1);
            int mini = *min_element(nums.begin() + left, nums.begin() + right + 1);

            if (maxi - mini <= d) {
                cnt++;
            }
            left++;
        }
    }
    return cnt;
}

int main() {
    vector<int> arr = {1, 3, 2, 6, 4, 5};
    int k = 3;
    int d = 2;

    long long ans = countStable(arr, k, d);

    cout << ans << endl;
    return 0;
}
