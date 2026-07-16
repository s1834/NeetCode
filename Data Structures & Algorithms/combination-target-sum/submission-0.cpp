class Solution {
private:
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(vector<int>& candidates, int target, int i) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        // if i == candidates.size() || sum exceeded target
        if(i == candidates.size() || target < 0) return;

        // Include candidates[i]
        curr.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], i);

        curr.pop_back();

        // Exclude candidates[i]
        dfs(candidates, target, i + 1);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ans;
    }
};