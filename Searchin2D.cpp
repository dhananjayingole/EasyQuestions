class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        int lo = 0;
        int hi = (n * m) - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            int new_row = mid / m; // convert mid index -> row
            int new_col = mid % m; // convert mid index -> column
            
            if (mat[new_row][new_col] == x) {
                return true;            // target found
            } 
            else if (mat[new_row][new_col] < x) {
                lo = mid + 1;           // search right half
            }
            else {
                hi = mid - 1;           // search left half
            }
        }
        return false; // not found
    }
};
