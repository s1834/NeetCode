class Solution {
private:
    int rotatedIndex(vector<int>& nums, int left, int right) {
        if (left == right) return left;

        if (nums[left] < nums[right]) return left;

        int mid = left + (right - left) / 2;

        if (nums[mid] >= nums[left]) return rotatedIndex(nums, mid + 1, right);

        return rotatedIndex(nums, left, mid);
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if(left > right) return -1;

        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if (nums[mid] < target) return binarySearch(nums, target, mid + 1, right);
        else return binarySearch(nums, target, left, mid - 1);
    }

public:
    int search(vector<int>& nums, int target) {
        int rotation = rotatedIndex(nums, 0, nums.size() - 1);
        if (rotation == 0) return binarySearch(nums, target, 0, nums.size() - 1);
        else if(target >= nums[0]) return binarySearch(nums, target, 0, rotation);
        else return binarySearch(nums, target, rotation, nums.size() - 1);
    }
};