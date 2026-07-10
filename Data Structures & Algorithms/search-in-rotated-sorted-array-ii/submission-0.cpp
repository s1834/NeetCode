class Solution {
private:
    bool binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left > right) return false;

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return true;

         // Eliminate duplicates
        if (nums[left] == nums[mid] && nums[mid] == nums[right]) return binarySearch(nums, target, left + 1, right - 1);

        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) return binarySearch(nums, target, left, mid - 1);
            else return binarySearch(nums, target, mid + 1, right);
        }

        // Right half is sorted
        if (nums[mid] < target && target <= nums[right]) return binarySearch(nums, target, mid + 1, right);
        else return binarySearch(nums, target, left, mid - 1);
    }

public:
    bool search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};