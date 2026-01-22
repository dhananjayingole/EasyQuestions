// first one is basically by traversing in reverse of the Array with loop.

class Solution {
public:
    // Function to reverse an array
    vector<int> reverseArray(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();

        // Create a new vector to store the reversed array
        vector<int> ans(n);

        // Loop through the array from start to end
        for(int i = n-1;i>=0;i--){
            ans.push_back(arr[i]);
        }

        // Return the reversed array
        return ans;
    }
};

// Second Approach is with two ptr apporach
vector<int> reverseArray(vector<int>& arr) {
        // Get the size of the array
        int p1 = 0;
        int p2 = arr.size()-1;
  // it only applies when you aplly only up to the n/2 size of the array
 while(p1< p2){
  swap(arr[p1], arr[p2]);

  p1++;

  p2--;
 }
}


// third mehtod is just like using reverse stl

reverse(arr.begin(), arr.end());
