class Solution {
private:
    int sum(int n) {
        int sum = 0;
        while(n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }

        return sum;
    }

public:
    bool isHappy(int n) {
        set<int> visited;
        while(visited.count(n) == 0) {
            visited.insert(n);
            n = sum(n);
            if(n == 1) return true;
        }
        return false;
    }
};