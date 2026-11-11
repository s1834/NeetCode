class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, int> mp1, mp2;
        for(auto &ch : s) mp1[ch]++;
        for(auto &ch : t) mp2[ch]++;

        if(mp1.size() != mp2.size()) return false;

        for(auto &x : mp1) {
            if(x.second != mp2[x.first]) return false;
        }

        return true;
    }
};