class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int x: nums) s.insert(x);
        
        int mx = 0;
        for(auto x : s) {
            int temp = x;
            if(s.find(temp - 1) == s.end()) {
                int count = 0;
                while(s.find(temp + count) != s.end()) count++;
                mx = max(mx, count);
            }
        }
        return mx;
    }
};