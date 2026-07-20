class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, n = nums.size(), mn = INT_MAX;
        long long sum = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum >= target) {
                mn = min(mn, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (mn == INT_MAX) ? 0 : mn;
    }
};