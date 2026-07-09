class Solution {
private:
    long long int subtract(vector<int>& piles, int speed) {
        long long int count = 0;
        for(int x : piles) count += ceil((double)x / speed);
        return count;
    }

    int binarySearch(vector<int>& piles, int h, int left, int right) {
        if(left > right) return left;
        int mid = left + (right - left) / 2;
        long long int count = subtract(piles, mid);
        if (count <= h) return binarySearch(piles, h, left, mid - 1);
        else return binarySearch(piles, h, mid + 1, right);
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = piles[0];
        for(auto x : piles) mx = max(mx, x);
        return binarySearch(piles, h, 1, mx);
    }
};