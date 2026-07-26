class Solution {
private:
    vector<string> ans;
    string s = "";
    unordered_map<char, vector<char>> mp;

    void dfs(string digits, int idx) {
        if(digits.size() == s.size()) {
            ans.push_back(s);
            return;
        }

        for(auto x : mp[digits[idx]]) {
            s += x;
            dfs(digits, idx + 1);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        mp['2'] = {'a','b','c'};
        mp['3'] = {'d','e','f'};
        mp['4'] = {'g','h','i'};
        mp['5'] = {'j','k','l'};
        mp['6'] = {'m','n','o'};
        mp['7'] = {'p','q','r','s'};
        mp['8'] = {'t','u','v'};
        mp['9'] = {'w','x','y','z'};

        dfs(digits, 0);
        return ans;
    }
};