class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3) return n;
        int a = 2, b = 3, c; // a = n(2), b = n(3)
        for(int i = 4; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};