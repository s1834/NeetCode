// Version 1: Recursion + Memoization 1
// class Solution {
// private:
//     int n, m;
//     vector<vector<int>> dp;

//     int solve(string& word1, string& word2, int i, int j) {
//         if(i == n) return m - j; // insert in word1
//         else if(j == m) return n - i; // delete from word2
        
//         if(dp[i][j] != -1) return dp[i][j];

//         if(word1[i] == word2[j]) return dp[i][j] = solve(word1, word2, i + 1, j + 1);
//         else {
//             int ins = 1 + solve(word1, word2, i, j + 1);
//             int del = 1 + solve(word1, word2, i + 1, j);
//             int rep = 1 + solve(word1, word2, i + 1, j + 1);

//             return dp[i][j] = min({ins, del, rep});
//         }

//         return -1;
//     }

// public:
//     int minDistance(string word1, string word2) {
//         n = word1.size();
//         m = word2.size();
//         dp.assign(n, vector<int>(m, -1));
//         return solve(word1, word2, 0, 0);
//     }
// };

// Version 2: Recursion + Memoization 2
// class Solution {
// private:
//     vector<vector<int>> dp;

//     int solve(string& word1, string& word2, int n, int m) {
//         if(n == 0 || m == 0) return n + m; 
        
//         if(dp[n][m] != -1) return dp[n][m];

//         if(word1[n - 1] == word2[m - 1]) return dp[n][m] = solve(word1, word2, n - 1, m - 1);
//         else {
//             int ins = 1 + solve(word1, word2, n, m - 1);
//             int del = 1 + solve(word1, word2, n - 1, m);
//             int rep = 1 + solve(word1, word2, n - 1, m - 1);

//             return dp[n][m] = min({ins, del, rep});
//         }

//         return -1;
//     }

// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
//         dp.assign(n + 1, vector<int>(m + 1, -1));
//         return solve(word1, word2, n, m);
//     }
// };

// Version 3: Bottom-Up
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i == 0 || j == 0) dp[i][j] = i + j;
                else if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    int ins = 1 + dp[i][j - 1];
                    int del = 1 + dp[i - 1][j];
                    int rep = 1 + dp[i - 1][j - 1];

                    dp[i][j] = min({ins, del, rep});
                }
            }
        }

        return dp[n][m];
    }
};