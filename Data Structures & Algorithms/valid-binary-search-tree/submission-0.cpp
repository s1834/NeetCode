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
    bool isValid(TreeNode* root, long long int mn, long long int mx) {
        if(!root) return true;
        if(root->val < mx && root->val > mn) return isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx);
        return false;
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};