class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0];
        int y = target[1];
        int z = target[2];

        bool xFound = false, yFound = false, zFound = false;
        int n = triplets.size();
        for(int i = 0; i < n; i++) {
            int a = triplets[i][0];
            int b = triplets[i][1];
            int c = triplets[i][2];

            if(a > x || b > y || c > z) continue;

            if(a == x) xFound = true;
            if(b == y) yFound = true;
            if(c == z) zFound = true;
        }

        return xFound && yFound && zFound;
    }
};