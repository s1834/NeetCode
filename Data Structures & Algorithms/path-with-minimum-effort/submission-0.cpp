class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // all 4 directions
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> result(n, vector<int>(m, INT_MAX)); // stores the minimum effort so far
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // pq<dist, {x, y}>
        pq.push({0, {0, 0}}); // first column
        result[0][0] = 0;

        while(!pq.empty()) {
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            // check all 4 directions
            for(auto dir : directions) {
                int a = x + dir[0];
                int b = y + dir[1];

                if(a >= 0 && b >= 0 && a < n && b < m) {
                    int dist = max(d, abs(heights[x][y] - heights[a][b])); // take the max of abs difference of all heights in the path
                    if (dist < result[a][b]) { // if the max of the abs difference of entire path is less than current
                        result[a][b] = dist;
                        pq.push({dist, {a, b}});
                    }
                }
            }
        }

        return result[n - 1][m - 1];
    }
};