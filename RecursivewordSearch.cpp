class Solution {
private:
    // Direction offsets for UP, RIGHT, DOWN, LEFT
    int dRow[4] = {-1, 0, 1, 0};
    int dCol[4] = {0, 1, 0, -1};

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if (index == word.length()) {
            return true;
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '$'; // Mark as visited

        for (int k = 0; k < 4; ++k) {
            int new_i = i + dRow[k];
            int new_j = j + dCol[k];

            if (dfs(board, word, new_i, new_j, index + 1)) {
                return true;
            }
        }

        board[i][j] = temp; // Backtrack
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};


// Q.2 Rat Maze Questions
#include <bits/stdc++.h>
using namespace std;

int dRow[4] = {-1, 0, 1, 0};
int dCol[4] = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};

void dfshelper(vector<vector<int>>& mat, int r, int c, string path, vector<string>& ans, vector<vector<bool>>& vis) {
    int n = mat.size();
    int m = mat[0].size();

    // 1st base case: Boundary check, blocked cell, or already visited
    if (r < 0 || c < 0 || r >= n || c >= m || mat[r][c] == 0 || vis[r][c]) {
        return;
    }

    // 2nd base case: Destination reached
    if (r == n - 1 && c == m - 1) {
        ans.push_back(path);
        return;
    }

    vis[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nrow = r + dRow[i];
        int ncol = c + dCol[i];
        dfshelper(mat, nrow, ncol, path + dir[i], ans, vis);
    }

    // Backtrack
    vis[r][c] = false;
}

vector<string> findPath(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<string> ans;
    string path = "";
    
    if (n == 0 || mat[0][0] == 0) return ans;

    vector<vector<bool>> vis(n, vector<bool>(n, false));
    dfshelper(mat, 0, 0, path, ans, vis);
    
    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> result = findPath(mat);

    for (const string& path : result) {
        cout << path << " ";
    }
    cout << endl;

    return 0;
}
