class Solution {
private:
    bool topologicalSort(int numCourses, unordered_map<int, vector<int>>& adj, vector<int>& indegree) {
        queue<int> q;
        int count = 0;

        // push which have indegree as 0
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                count++;
                q.push(i);
            }
        }
        
        // keep popping and pushing indegree with 0 until queue is empty
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int &v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    count++;
                    q.push(v);
                }
            }
        }

        // if count matches numCourses, that means we visited all nodes and no cycle exists
        if(count == numCourses) return true;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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