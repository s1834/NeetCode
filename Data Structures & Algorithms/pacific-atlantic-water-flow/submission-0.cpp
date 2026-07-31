class Solution {
private:

    void dfs(vector<vector<int>>& heights, set<pair<int, int>>& visited, int prevHeight, int i, int j) {
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) return; // out of bound
        if(visited.find({i, j}) != visited.end()) return; // already visited
        if(heights[i][j] < prevHeight) return; // current height less than previous height, so cant move to water

        // insert visited row and column and visit all four directions
        visited.insert({i, j});
        dfs(heights, visited, heights[i][j], i + 1, j);
        dfs(heights, visited, heights[i][j], i - 1, j);
        dfs(heights, visited, heights[i][j], i, j + 1);
        dfs(heights, visited, heights[i][j], i, j - 1);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        set<pair<int,int>> pacific, atlantic;

        // visit all columns of first and last row
        for(int i = 0; i < col; i++) {
            dfs(heights, pacific, heights[0][i], 0, i);
            dfs(heights, atlantic, heights[row - 1][i], row - 1, i);
        }

        // visit all rows of leftmost and rightmost columns
        for(int i = 0; i < row; i++) {
            dfs(heights, pacific, heights[i][0], i, 0);
            dfs(heights, atlantic, heights[i][col - 1], i, col - 1);
        }

        // check for the intersection of two sets
        vector<vector<int>> ans;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(pacific.find({i, j}) != pacific.end() && atlantic.find({i, j}) != atlantic.end()) ans.push_back({i, j});
            }
        }

        return ans;
    }
};