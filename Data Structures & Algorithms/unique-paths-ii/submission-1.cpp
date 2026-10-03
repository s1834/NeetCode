#include<bits/stdc++.h>

class Solution {
private:
    int n, m;
    int dp[101][101];

    int solve(vector<vector<int>>& obstacleGrid, int i, int j) {
        if(i == n - 1 && j == m - 1) return 1;
        if(i >= n || j >= m) return 0;

        if(obstacleGrid[i][j] == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(obstacleGrid, i + 1, j) + solve(obstacleGrid, i, j + 1);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        memset(dp, -1, sizeof(dp));

        if(obstacleGrid[0][0] || obstacleGrid[n - 1][m - 1]) return 0;

        return solve(obstacleGrid, 0, 0);
    }
};