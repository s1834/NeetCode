class Solution {
private:
    void fillNeighbours(queue<string>& q, unordered_set<string>& st, string curr) {
        // run for loop for 4 positions
        for(int i = 0; i < 4; i++) {
            char ch = curr[i]; // current version
                     
            char dec = ch == '0' ? '9' : ch - 1; // decrease curr
            char inc = ch == '9' ? '0' : ch + 1; // increase curr

            // check if decremented curr exists in deadend
            curr[i] = dec;
            if(st.find(curr) == st.end()) {
                q.push(curr);
                st.insert(curr);
            }

            // check if incremented curr exists in deadend
            curr[i] = inc;
            if(st.find(curr) == st.end()) {
                q.push(curr);
                st.insert(curr);
            }

            // backtrack curr char
            curr[i] = ch;
        }
    }

public:
    int openLock(vector<string>& deadends, string target) {
        // add deadends in a set
        unordered_set<string> st(deadends.begin(), deadends.end());

        // if starting position is deadend return -1
        if(st.find("0000") != st.end()) return -1;

        // add starting poisition in queue and it is also a deadend now as it is already visited
        queue<string> q;
        q.push("0000");
        st.insert("0000");

        int level = 0;
        while(!q.empty()) {
            int n = q.size();

            while(n--) {
                string curr = q.front();
                q.pop();

                if(curr == target) return level;

                fillNeighbours(q, st, curr);
            }

            level++;
        }

        return -1;
    }
};