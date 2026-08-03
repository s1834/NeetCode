class Solution {
private:
    void dfs(unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string>& visited, double& div, double prod, string src, string dst) {
        if(visited.find(src) != visited.end()) return; // already visited

        visited.insert(src);
        if(src ==  dst) { // divisor (b) found
            div = prod; 
            return;
        }

        for(auto &x : adj[src]) {
            string v = x.first; // a
            double value = x.second; // b
            dfs(adj, visited, div, prod * value, v, dst); // prod * value = multiply the values of between nodes
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        int n = equations.size();

        // create adjacency list unordered_map<dividend, {divisor, dividend/divisor}>
        for(int i = 0; i < n; i++) {
            string u = equations[i][0]; // a
            string v = equations[i][1]; // b
            double value = values[i]; // a / b

            adj[u].push_back({v, value}); // a / b
            adj[v].push_back({u, 1.0 / value}); // b / a
        }

        vector<double> ans;
        for(auto &query : queries) {
            string src = query[0]; // a
            string dst = query[1]; // b

            double div = -1.0; // division
            double prod = 1.0; // current product of graph
            
            if(adj.find(src) != adj.end()) {
                unordered_set<string> visited;
                dfs(adj, visited, div, prod, src, dst);
            }

            ans.push_back(div);
        }

        return ans;
    }
};