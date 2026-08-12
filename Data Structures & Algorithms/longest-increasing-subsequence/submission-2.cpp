class Solution {
private:
    int dp[2500][2500] = {};; // dp of constraints

    int solve(vector<int>& nums, int idx, int prevIdx) {
        if(idx >= nums.size()) return 0; // out of bound

        if(prevIdx != -1 && dp[idx][prevIdx]) return dp[idx][prevIdx]; // already calculated

        int take = 0;
        if(prevIdx == -1 || nums[prevIdx] < nums[idx]) take = 1 + solve(nums, idx + 1, idx);
        int skip = solve(nums, idx + 1, prevIdx);

        if(prevIdx != -1) return dp[idx][prevIdx] = max(take, skip); // save ans in dp
        return max(take, skip);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, 0, -1);
    }
};