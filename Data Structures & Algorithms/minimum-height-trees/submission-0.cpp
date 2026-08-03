class Solution {
private:
    vector<int> topologicalSort(int n, unordered_map<int, vector<int>>& adj, vector<int>& indegree) {
        queue<int> q;
        
        for(int i = 0; i < n; i++) if(indegree[i] == 1) q.push(i); // if indegree 1, push in queue (leaf node)

        while(n > 2) {
            int size = q.size();
            n -= size;
            
            while(size--) {
                int u = q.front();
                q.pop();

                for(auto &v : adj[u]) {
                    indegree[v]--;
                    if(indegree[v] == 1) q.push(v);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // n = 1; edges = []

        // create adjacency list of undirected graph
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return topologicalSort(n, adj, indegree); // perfrom topological sort until 1 or 2 are left
    }
};