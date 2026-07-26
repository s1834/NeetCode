class Solution {
    bool dfs(vector<int>& matchsticks, vector<int>& sides, int idx, int target) {
        if(idx == matchsticks.size()) {
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
        }

        for(int i = 0; i < 4; i++) {
            if(sides[i] + matchsticks[idx] <= target) {
                sides[i] += matchsticks[idx];
                if(dfs(matchsticks, sides, idx + 1, target)) return true;
                sides[i] -= matchsticks[idx];
            }
        }
        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        long long side = 0;
        for(auto& x : matchsticks) side += x;
        if(side % 4) return false;
        side /= 4;
        vector<int> sides(4, 0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return dfs(matchsticks, sides, 0, side);
    }
};