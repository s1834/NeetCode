class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // pair<pair<enqueueTime, processingTime>, index>>
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> available;

        // pair<processingTime, index>
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> process;

        // push all tasks in ascending order of enqueue time
        int n = tasks.size();
        for(int i = 0; i < n; i++) available.push({{tasks[i][0], tasks[i][1]}, i});

        // keep track of total time so far to add available to process queue
        long long int time = 1;
        vector<int> ans;
        while(!available.empty() || !process.empty()) {
            // push all enqueued tasks till current time for processing
            while(!available.empty() && available.top().first.first <= time) {
                process.push({available.top().first.second, available.top().second});
                available.pop();
            }

            // just choose the task with shortest processing time, and add its time to total time
            if(!process.empty()) {
                time += process.top().first;
                ans.push_back(process.top().second);
                process.pop();
            } else time = available.top().first.first;;
        }

        return ans;
    }
};