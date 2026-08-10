class Solution {
private:
    void dfs(unordered_map<string, vector<string>>& adj, vector<string>& path, string startNode) {
        while(!adj[startNode].empty()) {
            string newStartNode = adj[startNode].back();
            adj[startNode].pop_back(); // remove the last node (newStartNode) so we dont visit it twice in same path

            dfs(adj, path, newStartNode); // from newStartNode check if path exists again
        }

        path.push_back(startNode); // once all nodes exhasted push startNode in path
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Reverse sort so smallest destination is at the back (read question)
        sort(tickets.rbegin(), tickets.rend());
        
        // create adjacency list
        unordered_map<string, vector<string>> adj;
        for(auto ticket : tickets) adj[ticket[0]].push_back(ticket[1]); // u --> v
        

        vector<string> path;
        dfs(adj, path, "JFK");
        reverse(path.begin(), path.end()); // we recieve answers in reverse format

        return path;
    }
};