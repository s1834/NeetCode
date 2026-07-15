class Solution {
private:
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(vector<int>& nums, int i) {
         if (i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // Include nums[i]
        curr.push_back(nums[i]);
        dfs(nums, i + 1);

        curr.pop_back();
        
        // Exclude nums[i]
        dfs(nums, i + 1);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};