class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m) return false;

        unordered_map<char, int> mp1;
        for(auto x : s1) mp1[x]++;

        for(int i = 0; i < m - n + 1; i++) {
            unordered_map<char, int> mp2;
            for(int j = i; j < i + n; j++) mp2[s2[j]]++;
            if(mp1 == mp2) return true;
        }    

        return false;
    }
};