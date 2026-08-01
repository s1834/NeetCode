class Solution {
private:
    unordered_map<int, unordered_set<int>> topologicalSort(int numCourses, unordered_map<int, vector<int>>& adj, vector<int>& indegree) {
        queue<int> q;

        // push which have indegree as 0
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        // keep popping and pushing indegree with 0 until queue is empty
        unordered_map<int, unordered_set<int>> mp;
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int &v: adj[u]) {
                mp[v].insert(u); // insert u as a dependency/prerequisite in its adjacency list

                for(auto &x : mp[u]) mp[v].insert(x); // insert prerequisites of u as a dependency/prerequisite in its adjacency list

                indegree[v]--; // decrease in degeree of adjacency list nodes of u
                if(indegree[v] == 0) q.push(v);  // push if indegree becomes 0
            }
        }

        return mp;
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0); // Kahn's Algorithm
        
        for(auto &x : prerequisites) {
            // x[0]---->x[1]
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        unordered_map<int, unordered_set<int>> mp(topologicalSort(numCourses, adj, indegree));

        int q = queries.size();
        vector<bool> ans(q, false);
        for(int i = 0; i < q; i++) {
            // in queries[i] = [ui, vi]
            // check if mp[vi] contains ui as a prerequisite
            ans[i] = mp[queries[i][1]].contains(queries[i][0]);
        }

        return ans;  
    }
};