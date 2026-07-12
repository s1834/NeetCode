class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count number of occurrences of each char
        unordered_map<char, int> mp;
        for(auto x : tasks) mp[x]++;

        int time = 0;

        // push {count, char} in priority queue to sort by max occurrence
        priority_queue<pair<int, char>> pq;
        for(auto x : mp) pq.push({x.second, x.first});

        while(!pq.empty()) {
            queue<pair<int, char>> q; // queue to store elements until we can use it again
            int temp = n + 1; // n + 1 because current task + n 
            
            while(temp--) {
                if(!pq.empty()) {
                    pair<int, int> p = pq.top();
                    pq.pop();

                    time++;

                    // decrease 1 occurrence
                    p.first--;

                    // if still occurrences of that char left, push in queue
                    if(p.first > 0) q.push(p);
                } else {
                    if(q.empty()) break;
                    else time++;
                }
            }

            // push back the elements which can be used again now
            while(!q.empty()) {
                pq.push(q.front());
                q.pop();
            }
        }
        return time;
    }
};