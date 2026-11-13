class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), minSize = strs[0].size();
        for(int i = 0; i < n; i++) minSize = min(minSize, (int)strs[i].size());

        string ans = "";
        for(int i = 0; i < minSize; i++) {
            bool match = true;
            for(int j = 0; j < n; j++) {
                if(strs[j][i] != strs[0][i]) {
                    match = false;
                    break;
                }
            }
            if(match) ans += strs[0][i];
            else break;
        }

        return ans;
    }
};