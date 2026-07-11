/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> ans;
    int maxDepth = -1;

    void dfs(TreeNode* root, int depth) {
        if(!root) return;

        if(maxDepth < depth) {
            ans.push_back(root->val);
            maxDepth = depth;
        }

        dfs(root->right, depth + 1);
        dfs(root->left, depth + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};