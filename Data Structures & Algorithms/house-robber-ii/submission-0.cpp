class Solution {
private:
    int solve(vector<int>& nums, int l, int r) {
        int prevPrev = 0;
        int prev = 0;
        for(int i = l; i < r; i++) {
            int steal = prevPrev + nums[i];
            int skip = prev;

            int mx = max(steal, skip);

            prevPrev = prev;
            prev = mx;
        }
        
        return prev;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int skipOne = solve(nums, 0, n - 1);
        int stealOne = solve(nums, 1, n);

        return max(skipOne, stealOne);
    }
};