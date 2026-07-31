class Solution {
private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return; // out of bound
        if(board[i][j] == 'X' || board[i][j] == 'Y') return; // already 'X' or already flipped to 'Y'

        // flip 'O' to 'Y' and visit all four directions
        board[i][j] = 'Y';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

public:
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();

        // traverse all columns of top and bottom row
        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[row - 1][j] == 'O') dfs(board, row - 1, j);
        }

        // traverse all rows of left and right column
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][col - 1] == 'O') dfs(board, i, col - 1);
        }

        // flip 'O' to 'X' and 'Y' back to 'O'
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
};