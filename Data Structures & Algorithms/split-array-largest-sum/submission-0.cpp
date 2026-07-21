class Solution {
private:
    bool split(vector<int>& nums, int largest, int k) {
        int parts = 1, sum = 0;
        for(auto x : nums) {
            sum += x;
            if(sum > largest) {
                parts++;
                sum = x;
            }
        }
        return parts <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size(), left = INT_MIN, right = 0;
        for(int i = 0; i < n; i++){
            left = max(left, nums[i]);
            right += nums[i];
        } 
        int ans = right;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(split(nums, mid, k)) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }

        return ans;
    }
};