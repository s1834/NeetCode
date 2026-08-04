class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create adjacency list
        unordered_map<int, vector<pair<int, int>>> adj; // unordered_map<u, pair<v, weight>> adj;
        for(auto &x : times) {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap {shortest distance, node}
        vector<int> result(n + 1, INT_MAX); // result[i] = shortest distance from source k to node i
        result[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            int dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            // if a shorter path already exist, skip calculating agian
            if (dist > result[u]) continue;
            
            for(auto &node: adj[u]) {
                int v = node.first;
                int d = node.second;
                
                // If going through u gives a shorter path to v
                if(d + dist < result[v]) {
                    result[v] = d + dist;
                    pq.push({result[v], v});
                }
            }
        }

        // Find the maximum shortest distance
        int mx = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (result[i] == INT_MAX) return -1;
            mx = max(mx, result[i]);
        }

        return mx;
    }
};