class Solution {
private:
    int dfs(vector<int>& nums, int idx, int total) {
        if(nums.size() == idx) return total;
        return dfs(nums, idx + 1, total ^ nums[idx]) + dfs (nums, idx + 1, total);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);;
    }
};