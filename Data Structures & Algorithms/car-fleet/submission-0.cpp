class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        int n = position.size();
        for(int i = 0; i < n; i++) v.push_back({position[i], speed[i]});

        sort(v.begin(), v.end(), greater<pair<int, int>>());
        
        stack<double> st;
        for(auto x : v) {
            double time = (double)(target - x.first) / x.second;
            if(st.empty() || time > st.top()) st.push(time);
        }
        return st.size();
    }
};