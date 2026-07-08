class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int n = heights.size(), mx = 0;
        for(int i = 0; i < n; i++) {
            int start = i;
            while(!st.empty() && st.top().first > heights[i]) {
                int area = st.top().first * (i - st.top().second);
                mx = max(mx, area);
                start = st.top().second;
                st.pop();
            }
            st.push({heights[i], start});
        }
        while(!st.empty()) {
            int area = st.top().first * (n - st.top().second);
            mx = max(mx, area);
            st.pop();
        }
        return mx;
    }
};