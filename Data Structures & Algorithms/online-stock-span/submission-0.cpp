class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()) st.push({price, 0});
        else {
            int count = 0;
            while(!st.empty() && st.top().first <= price) {
                count += st.top().second + 1;
                st.pop();
            }
            st.push({price, count});
        }
        return st.top().second + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */