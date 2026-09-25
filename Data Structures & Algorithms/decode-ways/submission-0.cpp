class Solution {
private:
    int n;
    vector<int> dp;

    int solve(string& s, int i) {
        if(i == n) return 1;
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];
        
        // take 1 digit
        int ans = solve(s, i + 1);

        // take 2 digits
        if(i + 1 < n) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if(num >= 10 && num <= 26) ans += solve(s, i + 2);
        }

        return dp[i] = ans;
    }


public:
    int numDecodings(string s) {
        n = s.size();
        dp.assign(n, -1);
        return solve(s, 0);
    }
};