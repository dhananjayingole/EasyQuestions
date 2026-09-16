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
