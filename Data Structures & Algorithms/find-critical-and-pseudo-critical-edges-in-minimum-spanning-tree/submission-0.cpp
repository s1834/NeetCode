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
private:
    int Kruskal(int& n, vector<vector<int>>& edges, int skipEdge, int addEdge) {
        DSU dsu(n);
        int sum = 0, m = edges.size();

        // union the edge we want to add
        if(addEdge != -1) {
            dsu.Union(edges[addEdge][0], edges[addEdge][1]);
            sum += edges[addEdge][2];
        }

        for(int i = 0; i < m; i++) {
            if(i == skipEdge) continue; // if we need to skip this adge
            
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            int uParent = dsu.find(u);
            int vParent = dsu.find(v);

            if(uParent != vParent) {
                dsu.Union(u, v);
                sum += weight;
            }
        }
        
        // if parent not common / not a single graph
        for(int i = 0; i < n; i++) {
            if(dsu.find(i) != dsu.find(0)) return INT_MAX;
        }

        return sum;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for(int i = 0; i < m; i++) edges[i].push_back(i); // number each node edges[i] = [ai, bi, weighti, original index
        
        // custom comparator, compares weight
        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        };
        sort(edges.begin(), edges.end(), lambda);

        int mstWeight = Kruskal(n, edges, -1, -1);
        vector<int> critical; // paths which increase the mstWeight, if they are removed
        vector<int> pseudoCritical; // paths that keep the mstWeight same, if they are added
        
        for(int i = 0; i < m; i++) {
            if(Kruskal(n, edges, i, -1) > mstWeight) critical.push_back(edges[i][3]); // skip ith Edge
            else if(Kruskal(n, edges, -1, i) == mstWeight) pseudoCritical.push_back(edges[i][3]); // add ith Edge
        }

        return {critical, pseudoCritical};
    }
};