class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();

        // push all rotten oranges in queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        // all four directions
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int count = 0;
        
        while(!q.empty()) {
            int size = q.size();
            int flag = 0;

            while(size--) {
                // check 4 directions to this row and col
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];
                    
                    // if newRow and newCol are inside grid and are 1, push them in queue
                    if(newRow < n && newRow >= 0 && newCol < m && newCol >= 0) {
                        if(grid[newRow][newCol] == 1) {
                            grid[newRow][newCol] = 2;
                            q.push({newRow, newCol});
                            flag = 1;
                        }
                    }
                }
            }
            if(flag) count++;
        }

        // count the remaining islands which are not visited from boundry land
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return count;
    }
};