class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> from;
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> to;
        
        for(auto x : trips) from.push({x[1], x[2], x[0]});
        
        while(!from.empty()) {
            auto [a, b, c] = from.top();
            from.pop();

            while(!to.empty()) {
                auto [x, y] = to.top();
                if(a >= x) {
                    capacity += y;
                    to.pop();
                } else break;
            }

            to.push({b, c});
            capacity -= c;
            if(capacity < 0) return false; 
        }

        return true;
    }
};