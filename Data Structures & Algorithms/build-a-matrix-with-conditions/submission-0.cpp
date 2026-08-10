class Solution {
private:
    vector<int> topologicalSort(vector<vector<int>>& edges, int& k) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(k + 1, 0);

        // create adjacency list and indegree
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v); // u --> v
            indegree[v]++;
        }

        // push all in queue with indegree as 0
        queue<int> q;
        int count = 0;
        for(int i = 1; i <= k; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }

        // create topological order
        vector<int> topologicalOrder;
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            topologicalOrder.push_back(u);

            for(int &v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }

        if(count != k) return {}; // if all nodes not visited return {}
        return topologicalOrder;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // do topological sort on both row and col conditions to find the desired order
        vector<int> topologicalRow = topologicalSort(rowConditions, k);
        vector<int> topologicalCol = topologicalSort(colConditions, k);

        // found cycle, answer not possible
        if(topologicalRow.empty() || topologicalCol.empty()) return {};

        vector<vector<int>> ans (k, vector<int>(k, 0));
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                if(topologicalRow[i] == topologicalCol[j]) ans[i][j] = topologicalRow[i]; // if both row and col index found push it in ans
            }
        }

        return ans;
    }
};