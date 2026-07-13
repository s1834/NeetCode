class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int, char>> pq;
        
        // if characters are not 0, push in queue
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});

        string ans = "";

        while(!pq.empty()) {
            
            auto temp = pq.top();
            pq.pop();

            int n = ans.size();
            // check we are forming 3 consecutive chars
            if(n > 1 && ans[n - 1] == temp.second && ans[n - 2] == temp.second) {
                // if adding temp forms 3 consecutive, append topmost element of pq
                if(pq.empty()) break;
                auto p = pq.top();
                pq.pop();

                ans += p.second;
                p.first--;

                // push p and temp again for next iteration
                if(p.first > 0) pq.push(p);

                pq.push(temp);
            }
            else {
                // if we are not forming 3 consecutive then simply append the temp char
                ans += temp.second;
                temp.first--;
                if(temp.first > 0) pq.push(temp);
            }
        }

        return ans;
    }
};