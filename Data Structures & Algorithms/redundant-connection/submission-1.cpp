// Version 1: DFS
// class Solution {
// private:
//     bool dfs(unordered_map<int, vector<int>>& adj, unordered_set<int>& visited, int u, int v) {
//         // if u == v then we found a cycle
//         if(u == v) return true;

//         // make current node, 'u' as visited
//         visited.insert(u);

//         // explore all nodes in adjacency and keep checking if they are already visited or not
//         for(auto &x : adj[u]) {
//             if(!visited.count(x) && dfs(adj, visited, x, v)) return true;
//         }

//         return false;
//     }

// public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         unordered_map<int, vector<int>> adj;
//         for(auto &edge : edges) {
//             int u = edge[0];
//             int v = edge[1];

//             unordered_set<int> visited;

//             // check if u and v are already connected
//             if(dfs(adj, visited, u, v)) return edge;

//             // add edge to graph
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         return {};
//     }
// };


// Version 2: Disjoint Set Union (DSU)
class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        // resize to fit all nodes
        parent.resize(n + 1);
        rank.resize(n + 1);

        // initally assign each node as its parent and rank as 0
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if(parent[x] == x) return x; // if parent has parent as itself
        return parent[x] = find(parent[x]); // else find the parent of parent and do path compression
    }

    void Union(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);

        if(xParent == yParent) return; // if both have same parent, they belong to same set

        if(rank[xParent] > rank[yParent]) parent[yParent] = xParent; // if xParent has higher rank(more children), make it parent of y
        else if(rank[xParent] < rank[yParent]) parent[xParent] = yParent; // if yParent has higher rank(more children), make it parent of x
        else { // if both have equal rank(equal children), make anyone as parent and increase that parent rank
            parent[yParent] = xParent;
            rank[xParent]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            unordered_set<int> visited;

            // if both have same parent they are already connected
            if(dsu.find(u) == dsu.find(v)) return edge;

            // add edge between u and v
            dsu.Union(u, v);
        }

        return {};
    }
};