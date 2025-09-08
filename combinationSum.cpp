// Great question 💡 Let’s do a **step-by-step dry run** of the **Optimized Backtracking Approach** on

// ```
// candidates = [10,1,2,7,6,1,5], target = 8
// ```

// ---

// ### 🔹 Step 1: Sort the candidates

// ```
// candidates = [1,1,2,5,6,7,10]
// ```

// ---

// ### 🔹 Step 2: Start recursion

// We begin with:

// ```
// target = 8
// path = []
// start = 0
// ```

// ---

// ### 🔹 Step 3: Explore candidates one by one

// #### i = 0 → candidate = 1

// ```
// path = [1], target = 7
// ```

// Recursive call.

// ---

// #### Inside recursion (start=1, target=7)

// * **i = 1 → candidate = 1**

//   ```
//   path = [1,1], target = 6
//   ```

//   Recursive call.

//   * **i = 2 → candidate = 2**

//     ```
//     path = [1,1,2], target = 4
//     ```

//     Recursive call.

//     * **i = 3 → candidate = 5**
//       5 > 4 ❌ (stop here)

//     * **i = 4 → candidate = 6**
//       6 > 4 ❌

//     * **i = 5 → candidate = 7**
//       7 > 4 ❌

//     * **i = 6 → candidate = 10**
//       10 > 4 ❌

//     Backtrack → `path = [1,1]`

//   * **i = 3 → candidate = 5**

//     ```
//     path = [1,1,5], target = 0 ✅ FOUND!
//     ```

//     Save: **\[1,1,6]**
//     Backtrack.

// ---

// Back at `path = [1]`, target=7

// * **i = 2 → candidate = 2**

//   ```
//   path = [1,2], target = 5
//   ```

//   Recursive call.

//   * **i = 3 → candidate = 5**

//     ```
//     path = [1,2,5], target = 0 ✅ FOUND!
//     ```

//     Save: **\[1,2,5]**

//   * **i = 4 → candidate = 6**
//     6 > 5 ❌

//   * **i = 5 → candidate = 7**
//     7 > 5 ❌

// Backtrack.

// ---

// Still in `path = [1]`, target=7

// * **i = 3 → candidate = 5**

//   ```
//   path = [1,5], target = 2
//   ```

//   → Next candidates are 6,7,10 (all > 2) → dead end.

// * **i = 4 → candidate = 6**

//   ```
//   path = [1,6], target = 1
//   ```

//   → Next candidates > 1 → dead end.

// * **i = 5 → candidate = 7**

//   ```
//   path = [1,7], target = 0 ✅ FOUND!
//   ```

//   Save: **\[1,7]**

// Backtrack to `path = []`.

// ---

// ### 🔹 Step 4: Next start candidates

// * **i = 1 → candidate = 1**

//   * This is a duplicate of previous `candidates[0]`, and since `i > start`, we **skip** it.
//     ✅ This is how duplicates are avoided.

// ---

// * **i = 2 → candidate = 2**

//   ```
//   path = [2], target = 6
//   ```

//   Recursive call.

//   * **i = 3 → candidate = 5**
//     path = \[2,5], target = 1 → dead end.

//   * **i = 4 → candidate = 6**

//     ```
//     path = [2,6], target = 0 ✅ FOUND!
//     ```

//     Save: **\[2,6]**

//   * **i = 5 → candidate = 7**
//     7 > 6 ❌

// ---

// * **i = 3 → candidate = 5**

//   ```
//   path = [5], target = 3
//   ```

//   Next values > 3 → dead end.

// * **i = 4 → candidate = 6**

//   ```
//   path = [6], target = 2
//   ```

//   Next values > 2 → dead end.

// * **i = 5 → candidate = 7**

//   ```
//   path = [7], target = 1
//   ```

//   Next values > 1 → dead end.

// * **i = 6 → candidate = 10**
//   10 > 8 ❌

// ---

// ### 🔹 Final Result Collected

// ```
// [
//  [1,1,6],
//  [1,2,5],
//  [1,7],
//  [2,6]
// ]
// ```

// ✅ Matches expected output.

// ---

// 👉 The **key trick** here is:

// * Sorting first.
// * Skipping duplicates: `if (i > start && candidates[i] == candidates[i-1]) continue;`.

// ---

// Would you like me to also show the **recursion tree diagram** for this example (like a branching tree), so you can **visualize** how backtracking explores and prunes paths?


class Solution {
public:
    vector<vector<int>>result;

    void backtrack(vector<int>& candidates, int target, int start, vector<int>& path){
        if(target == 0){
            result.push_back(path);
            return;
        }

        for(int i = start; i < candidates.size();i++){
            if(i > start && candidates[i] == candidates[i-1]) continue;

            if(candidates[i] > target) break;

            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i+1, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>path;
        backtrack(candidates, target, 0, path);
        return result;
    }
};
