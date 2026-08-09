class Solution {
private:
    int primsAlgorithm(vector<vector<pair<int, int>>>& adj, int& v) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // node, weight
        pq.push({0, 0}); // put {weight, node} = {0, 0} to start pq
        vector<bool> inMST(v, false); // check if node is already visited
        int sum = 0;

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int weight = p.first;
            int node = p.second;

            if(inMST[node]) continue; // if already visited
            
            // mark visited
            inMST[node] = true;
            sum += weight;

            // visit all adjacent nodes of current node
            for(auto &v : adj[node]) {
                int neighbor = v.first;
                int neighborWeight = v.second;
                
                // if not visited, push in pq
                if(!inMST[neighbor]) pq.push({neighborWeight, neighbor});
            }
        }
        
        return sum;
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        vector<vector<pair<int, int>>> adj(v); // i -> j, weight
        for(int i = 0; i < v; i++) {
            for(int j = i + 1; j < v; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2); // manhattan distance 

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        
        return primsAlgorithm(adj, v);
    }
};