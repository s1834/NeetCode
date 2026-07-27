class Solution {
private:
    vector<vector<string>> ans;
    vector<string> board;
    set<int> col;
    set<int> posDia; // r + c
    set<int> negDia; // r - c
    
    void backtrack(int row, int n) {
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++) {
            if(col.find(c) != col.end() || posDia.find(row + c) != posDia.end() || negDia.find(row - c) != negDia.end()) continue;

            col.insert(c);
            posDia.insert(row + c);
            negDia.insert(row - c);
            board[row][c] = 'Q';


            backtrack(row + 1, n);

            col.erase(c);
            posDia.erase(row + c);
            negDia.erase(row - c);
            board[row][c] = '.';

        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        board.assign(n, string(n, '.'));
        backtrack(0, n);
        return ans;
    }
};