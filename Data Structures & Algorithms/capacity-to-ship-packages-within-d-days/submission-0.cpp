class Solution {
private:
    long long int findDays(vector<int>& weights, int capacity) {
        long long int count = 0;
        int temp = 0;
        for(int x : weights) {
            if(temp < x) {
                count++;
                temp = capacity;
            }
            temp -= x;
        }
        return count;
    }
    
    int binarySearch(vector<int>& weights, int days, int left, int right) {
        if(left > right) return left;
        int mid = left + (right - left) / 2;
        int count = findDays(weights, mid);
        if(count <= days) return binarySearch(weights, days, left, mid - 1);
        else return binarySearch(weights, days, mid + 1, right);
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mx = weights[0], total = 0;
        for(auto x : weights){
            mx = max(mx, x);
            total += x;
        }
        return binarySearch(weights, days, mx, total);
    }
};