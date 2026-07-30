class Solution {
private:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        int row = grid.size(), col = grid[0].size();

        // if we are outside grid, add 1
        if(i >= row || i < 0 || j >= col || j < 0) return 0;
        
        // if water, add 1
        if(grid[i][j] == 0) return 0;

        // Already visited land
        if(visited[i][j]) return 0;

        visited[i][j] = 1;

        int count = 0;
        count++;

        // Check all four directions
        count += dfs(grid, visited, i-1, j); // up
        count += dfs(grid, visited, i+1, j); // down
        count += dfs(grid, visited, i, j-1); // left
        count += dfs(grid, visited, i, j+1); // right

        return count;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));
        int ans = 0;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) ans = max(ans, dfs(grid, visited, i, j));
            }
        }

        return ans;
    }
};