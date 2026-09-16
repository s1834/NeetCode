// Version 1: Recursion + Memoization
// class Solution {
// private:
//     int n;
//     vector<vector<int>> dp;

//     bool isPalindrome(string& s, int i, int j) {
//         while(i < j) {
//             if(s[i] != s[j]) return false;
//             i++;
//             j--;
//         }
//         return true;
//     }

//     int solve(string& s, int i, int j) {
//         if(j >= n) return 0;

//         if(dp[i][j] != -1) return 0;

//         int take = isPalindrome(s, i, j) ? 1 : 0;
//         int left = solve(s, i + 1, (i + 1 > j) ? j + 1 : j);
//         int right = solve(s, i, j + 1);

//         return dp[i][j] = take + left + right;
//     }

// public:
//     int countSubstrings(string s) {
//         n = s.size();
//         dp.assign(n + 1, vector<int>(n + 1, -1));
//         return solve(s, 0, 0);
//     }
// };

// Version 2: Bottom-Up
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int l = 1; l <= n; l++) {
            for(int i = 0; i + l - 1 < n; i++) {
                int j = i + l - 1;

                if(i == j) dp[i][j] = true;
                else if(i + 1 == j) dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                
                if(dp[i][j]) count++;
            }
        }

        return count;
    }
};