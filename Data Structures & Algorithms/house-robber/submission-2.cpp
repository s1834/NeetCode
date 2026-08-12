// Version 1: Recursion + Memoization

// #include <cstring>

// class Solution {
// private: 
//     int t[101]; // dp

//     int solve(vector<int>& nums, int i) {
//         if(i >= nums.size()) return 0;

//         if(t[i] != -1) return t[i];

//         int steal = nums[i] + solve(nums, i + 2); // include nums[i];
//         int skip = solve(nums, i + 1); // not include nums[i];

//         return t[i] = max(steal, skip);
//     }

// public:
//     int rob(vector<int>& nums) {
//         memset(t, -1, sizeof(t));
//         return solve(nums, 0);
//     }
// };

// Version 2: Bottom-Up DP

class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
    
            int prevPrev = 0;
            int prev = nums[0];
    
            for(int i = 1; i < n; i++) {
                int skip = prev; // if skipped this house
                int steal = nums[i] + prevPrev; // we rob this house, wo we have to rob the house before the before house
    
                int mx = max(skip, steal);
    
                prevPrev = prev;
                prev = mx;
            }
    
            return prev;
        }
    };