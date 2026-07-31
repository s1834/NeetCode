class Solution {
private:
    vector<int> topologicalSort(int numCourses, unordered_map<int, vector<int>>& adj, vector<int>& indegree) {
        queue<int> q;
        vector<int> ans;

        // push which have indegree as 0
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }

        // keep popping and pushing indegree with 0 until queue is empty
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int& v: adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                    ans.push_back(v);
                }
            }
        }

        // if ans.size() matches numCourses, that means we visited all nodes and no cycle exists
        if(ans.size() == numCourses) return ans;
        return {};
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0); // Kahn's Algorithm
        
        for(auto &x : prerequisites) {
            // x[1]---->x[0]
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        return topologicalSort(numCourses, adj, indegree);
    }
};