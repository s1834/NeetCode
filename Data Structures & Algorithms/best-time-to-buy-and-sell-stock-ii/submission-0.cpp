class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cheap = prices[0], n = prices.size(), mx = 0;

        for (int i = 0; i < n - 1; i++) {
            if (prices[i] < cheap) {
                cheap = prices[i];
            }

            if (prices[i + 1] < prices[i]) {
                mx += prices[i] - cheap;
                cheap = prices[i];
            }
        }

        if(cheap < prices[n - 1]) mx += prices[n - 1] - cheap;

        return mx;  
    }
};