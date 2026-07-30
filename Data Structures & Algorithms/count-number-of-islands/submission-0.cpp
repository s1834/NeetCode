class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        // i, j out of grid
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0) return;

        // water
        if(grid[i][j] == '0') return;

        // already visited
        if (visited[i][j]) return;

        // visit
        visited[i][j] = true;
        
        // explaore all 4 directions
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i, j + 1);
        dfs(grid, visited, i, j - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), islands = 0;
        vector<vector<bool>> visited (n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    dfs(grid, visited, i, j);
                }
            }
        }

        return islands;   
    }
};