class Solution {
private:
    int binarySearch(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];

        if (nums[left] < nums[right]) return nums[left];

        int mid = left + (right - left) / 2;

        if (nums[mid] >= nums[left]) return binarySearch(nums, mid + 1, right);

        return binarySearch(nums, left, mid);
    }

public:
    int findMin(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }
};