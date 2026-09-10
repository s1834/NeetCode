class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int l = 0, r = 0, n = s.size(), mx = 0, count = 0;
        while(r < n) {
            while(st.find(s[r]) != st.end()) {
                st.erase(s[l]);
                l++;
                mx = max(mx, count);
                count--;
            }
            st.insert(s[r]);
            count++;
            r++;
        }
        return max(mx, count);
    }
};