class Solution {
private:
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int idx) {
        // word found
        if (idx == word.size()) return true;
        
        // invalid index of row or col
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;

        // char doesnt match
        if (board[row][col] != word[idx]) return false;

        // visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Explore all 4 directions
        bool found = 
            dfs(board, word, row + 1, col, idx + 1) || // down
            dfs(board, word, row - 1, col, idx + 1) || // up
            dfs(board, word, row, col + 1, idx + 1) || // right
            dfs(board, word, row, col - 1, idx + 1); // left

        // Backtrack
        board[row][col] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        // use each char as starting point
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};