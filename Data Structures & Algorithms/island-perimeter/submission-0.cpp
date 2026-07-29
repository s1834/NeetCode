class Solution {
private:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        int row = grid.size(), col = grid[0].size();

        // if we are outside grid, add 1
        if(i >= row || i < 0 || j >= col || j < 0) return 1;
        
        // if water, add 1
        if(grid[i][j] == 0) return 1;

        // Already visited land
        if(visited[i][j]) return 0;

        visited[i][j] = 1;

        int perimeter = 0;

        // Check all four directions
        perimeter += dfs(grid, visited, i-1, j); // up
        perimeter += dfs(grid, visited, i+1, j); // down
        perimeter += dfs(grid, visited, i, j-1); // left
        perimeter += dfs(grid, visited, i, j+1); // right

        return perimeter;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) return dfs(grid, visited, i, j);
            }
        }

        return 0;
    }
};