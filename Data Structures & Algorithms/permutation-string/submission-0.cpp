class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if(m > n) return false;

        unordered_map<char, int> mp1, mp2;
        for(auto x : s1) mp1[x]++;

        for(int i = 0; i < m; i++) {
            if(mp1.find(s2[i]) != mp1.end()) mp2[s2[i]]++;
        }

        int left = 0, right = m - 1;
        while(right < n) {
            if(mp1.size() == mp2.size()) {
                int flag = true;
                for(auto x : mp1) {
                    if(x.second != mp2[x.first]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) return true;
            }

            if(mp1.find(s2[left]) != mp1.end()) {
                mp2[s2[left]]--;
                if(mp2[s2[left]] == 0) mp2.erase(s2[left]);
            }
            left++;
            right++;
            if(right < n && mp1.find(s2[right]) != mp1.end()) mp2[s2[right]]++;

        }
        return false;
    }
};