class Solution {
private:
    bool dfs(vector<int>& nums, int k, vector<int>& parts, int idx, int target) {
        if(idx == nums.size()) {
            for(int i = 0; i < k; i++) {
                if(parts[i] != target) return false;
            }
            return true;
        }

        for(int i = 0; i < k; i++) {
            if(i > 0 && parts[i] == parts[i - 1]) continue;

            if(parts[i] + nums[idx] <= target) {
                parts[i] += nums[idx];
                if(dfs(nums, k, parts, idx + 1, target)) return true;
                parts[i] -= nums[idx];
            }
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long sum = 0;
        for(auto& x : nums) sum += x;
        if(sum % k) return false;
        sum /= k;
        vector<int> parts(k, 0);
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(nums, k, parts, 0, sum);
    }
};