class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(char x : s) mp[x]++;

        priority_queue<pair<int, char>> pq;
        for(auto x : mp) pq.push({x.second, x.first});

        string ans = "";
        while(!pq.empty()) {
            if(pq.size() == 1) {
                if(pq.top().first > 1) return "";
                else {
                    ans += pq.top().second;
                    return ans;
                }
            }
            else {
                pair<int, char> temp = pq.top();
                pq.pop();
                ans += temp.second;
                temp.first--;

                pair<int, char> p = pq.top();
                pq.pop();
                ans += p.second;
                p.first--;
                if(p.first != 0) pq.push(p);
                if(temp.first != 0) pq.push(temp);
            }
        }

        return ans;
    }
};