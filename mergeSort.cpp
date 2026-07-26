#include <bits/stdc++.h>
using namespace std;

// Added '&' to pass vector by reference
void merge(vector<int>& nums, int low, int mid, int high) {
    int an = mid - low + 1;
    int bn = high - mid;
    
    vector<int> L1(an);
    vector<int> L2(bn);
    
    for (int i = 0; i < an; i++) {
        L1[i] = nums[low + i];
    }
    for (int j = 0; j < bn; j++) {
        L2[j] = nums[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = low;
    
    while (i < an && j < bn) {
        if (L1[i] <= L2[j]) { // Added '=' for stable sorting
            nums[k++] = L1[i++];
        } else {
            nums[k++] = L2[j++];
        }
    }
    
    while (i < an) {
        nums[k++] = L1[i++];
    }
    while (j < bn) {
        nums[k++] = L2[j++];
    }
}

// Fixed: changed 'while' to 'if', added '&'
void mergeSort(vector<int>& nums, int low, int high) {
    if (low < high) { 
        int mid = low + (high - low) / 2;
        
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}

int main() {
    int size;
    cout << "Size of arr: ";
    cin >> size;
    
    vector<int> nums(size);
    
    cout << "Enter Ele: ";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    
    mergeSort(nums, 0, nums.size() - 1);
    
    // Print final sorted array here
    cout << "Sorted Array: ";
    for (int ele : nums) {
        cout << ele << " ";
    }
    cout << endl;
    
    return 0;
}
