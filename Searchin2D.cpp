class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        int lo = 0;
        int hi = (n * m) - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            int new_row = mid / m; // converting mid index -> row
            int new_col = mid % m; // converting mid index -> column
            
            if (mat[new_row][new_col] == x) {
                return true;            // target ele found
            } 
            else if (mat[new_row][new_col] < x) {
                lo = mid + 1;           // search in right half
            }
            else {
                hi = mid - 1;           // search in left half
            }
        }
        return false; // not found
    }
};
