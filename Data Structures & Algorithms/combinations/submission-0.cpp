class Solution {
private:
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int n, int k, int i) {
        if(!k) {
            ans.push_back(curr);
            return;
        }

        if(i > n) return;

        curr.push_back(i);
        dfs(n, k - 1, i + 1);
        curr.pop_back();

        dfs(n, k, i + 1);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
};