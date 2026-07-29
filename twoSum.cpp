// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;

vector<int>twoSum(vector<int>nums, int target){
    int n = nums.size();
    vector<int>ans;
    unordered_map<int, int>mpp;
    
    for(int i=0;i<n;i++){
        int complement = target - nums[i];
        
        if(mpp.find(complement) != mpp.end()){
            ans.push_back(i);
            ans.push_back(mpp[complement]);
            return ans;
        }
        
        mpp[nums[i]] = i; // pushing index value with Complement into the Map.
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    
    vector<int> nums(n);
    
    cout << "Enter Ele Values: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    int target;
    cout << "Enter Target: ";
    cin >> target; // FIXED: changed 'n' to 'target'
    
    // FIXED: Changed return type from 'int' to 'vector<int>'
    vector<int> result = twoSum(nums, target);
    // FIXED: Looping to print the indices vector
    if(!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }
    
    return 0;
}
