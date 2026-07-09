class Solution {
private:
    int binarySearch(int target, int left, int right) {
        if(left > right) return right;

        int mid = left + (right - left) / 2;
        long long int square = 1LL * mid * mid;
        if(square == target) return mid;
        else if(square < target) return binarySearch(target, mid + 1, right);
        else return binarySearch(target, left, mid - 1);
    }

public:
    int mySqrt(int x) {
        return binarySearch(x, 0, x);
    }
};