class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for(int i = 0; i <= k; i++) {
            vector<int> temp = prices;

            for(auto flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                if(prices[from] == INT_MAX) continue; // check with prices not temp
                if(prices[from] + price < temp[to]) temp[to] = prices[from] + price; // prices[from], not temp[from]
            }
            prices = temp;
        }

        if(prices[dst] == INT_MAX) return -1;
        return prices[dst];
    }
};