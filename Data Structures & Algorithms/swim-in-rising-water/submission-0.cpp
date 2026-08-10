class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // all 4 directions
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // pq<time, {x, y}>
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pq.push({grid[0][0], {0, 0}}); // first column

        while(!pq.empty()) {
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (visited[x][y]) continue;
            visited[x][y] = true; // mark visited

            if(x == n - 1 && y == n - 1) return time; // reached (n - 1, n - 1)

            // visit all 4 directions
            for(auto &dir : directions) {
                int a = x + dir[0];
                int b = y + dir[1];

                if(a >= 0 && b >= 0 && a < n && b < n && !visited[a][b]) pq.push({max(time, grid[a][b]), {a, b}}); // pq.push({maximum time to reach so far, {coordinates}})
            }   
        }

        return -1;
    }
};