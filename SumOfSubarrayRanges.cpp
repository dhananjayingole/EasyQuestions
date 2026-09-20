#include <bits/stdc++.h>
using namespace std;

void generate(int start, int end, vector<int>& curr, vector<int>& nums, vector<vector<int>>& ans) {
    if (end == nums.size()) {
        return;
    }

    curr.push_back(nums[end]);
    ans.push_back(curr);

    generate(start, end + 1, curr, nums, ans);

    curr.pop_back();
}

void getSubarray(int start, vector<int>& nums, vector<vector<int>>& ans) {
    if (start == nums.size()) {
        return;
    }

    vector<int> curr;
    generate(start, start, curr, nums, ans);

    getSubarray(start + 1, nums, ans);
}

vector<vector<int>> getallsubarray(vector<int>& nums) {
    vector<vector<int>> ans;
    getSubarray(0, nums, ans);
    return ans;
}

long long SubArrayRanges(vector<int>& nums) {
    long long totalSum = 0;

    // Value copy instead of non-const lvalue reference
    vector<vector<int>> ans = getallsubarray(nums);

    for (const auto& subarray : ans) {
        int minval = subarray[0];
        int maxval = subarray[0];

        for (int val : subarray) {
            minval = min(minval, val);
            maxval = max(maxval, val); // Fixed: changed min to max
        }

        totalSum += (maxval - minval);
    }
    return totalSum;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = getallsubarray(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }

    // Calculate total sum of ranges.
    long long totalRangeSum = SubArrayRanges(nums);
    cout << "Total sum of Subarray ranges: " << totalRangeSum << endl;

    return 0;
}


// More Optimised or Easy Way is there.
  class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;

        for(int i=0;i<n;i++){
            int minval = nums[i];
            int maxval = nums[i];

            for(int j=i;j<n;j++){
                minval = min(minval, nums[j]);
                maxval = max(maxval, nums[j]);

                totalSum += (maxval - minval);
            }
        }
        return totalSum;
    }
};

// More 
