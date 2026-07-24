/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private: 
    int binarySearch(MountainArray &mountainArr, int target, int left, int right, bool asc) {
        if (left > right) return -1;

        int mid = left + (right - left) / 2;
        int num = mountainArr.get(mid);

        if (num == target) return mid;
        else if (asc) {
            if (num > target) return binarySearch(mountainArr, target, left, mid - 1, true);
            else return binarySearch(mountainArr, target, mid + 1, right, true);
        } else {
            if (num > target) return binarySearch(mountainArr, target, mid + 1, right, false);
            else return binarySearch(mountainArr, target, left, mid - 1, false);
        }
    }

    int findMax(MountainArray &mountainArr, int target, int left, int right) {
        if(left == right) {
            int first = binarySearch(mountainArr, target, 0, left, true);
            int second = binarySearch(mountainArr, target, left + 1, mountainArr.length() - 1, false);

            if (first == -1) return second;
            if (second == -1) return first;
            return min(first, second);
        } 

        int mid = left + (right - left) / 2;
        int r = mountainArr.get(mid + 1), m = mountainArr.get(mid);
        if(m < r) return findMax(mountainArr, target, mid + 1, right);
        else return findMax(mountainArr, target, left, mid);
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        return findMax(mountainArr, target, 0, mountainArr.length() - 1);
    }
};