class Solution {
    public:
        string minWindow(string s, string t) {
            int m = s.size(), n = t.size();
            if(m < n) return "";
            
            unordered_map<char, int> mp1, mp2;
            for(char c : t) mp1[c]++;
    
            int l = 0, r = 0, start = 0, length = m + 1, have = 0, need = mp1.size();
            while(r < m) {
                mp2[s[r]]++;
                if(mp1.count(s[r]) && mp1[s[r]] == mp2[s[r]]) have++;
    
                while(have == need) {
                    if (r - l + 1 < length) {
                        length = r - l + 1;
                        start = l;
                    }
    
                    mp2[s[l]]--;
                    if (mp1.count(s[l]) && mp2[s[l]] < mp1[s[l]]) have--;
                    l++;
                }
                r++;
            }
    
            if(length == m + 1) return "";
            return s.substr(start, length);
        }
    };