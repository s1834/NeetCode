class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int l = 1; l <= n; l++) {
            for(int i = 0; i + l - 1 < n; i++) {
                int j = i + l - 1;

                if(i == j) dp[i][j] = true;
                else if(i + 1 == j) dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                
                if(dp[i][j] && (j - i + 1 > ans.size())) ans = s.substr(i, j - i + 1);
            }
        }

        return ans;
    }
};