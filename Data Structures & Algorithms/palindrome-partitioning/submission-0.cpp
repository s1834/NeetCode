class Solution {
private: 
    vector<vector<string>> ans;
    vector<string> part;

    bool isPalindrome(string s) {
        int first = 0, last = s.size() - 1;
        while(first < last) {
            if(s[first] != s[last]) return false;
            first++;
            last--;
        }
        return true;
    }

    void dfs(string& s, int start) {
        if(start == s.size()) {
            ans.push_back(part);
            return;
        }

        int n = s.size();
        for(int i = start; i < n; i++) {
            string x = s.substr(start, i - start + 1);
            if(isPalindrome(x)) {
                part.push_back(x);
                dfs(s, i + 1);
                part.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ans;
    }
};