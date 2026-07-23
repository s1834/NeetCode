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
    int search(vector<int>& inorder, int rootVal, int start, int end) {
        for(int i = start; i <= end; i++) if(inorder[i] == rootVal) return i;
        return 0;
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& idx, int start, int end) {
        if(start > end) return NULL;

        int rootVal = preorder[idx];
        int i = search(inorder, rootVal, start, end);

        idx++;

        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preorder, inorder, idx, start, i - 1);
        root->right = build(preorder, inorder, idx, i + 1, end);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return build(preorder, inorder, idx, 0, preorder.size() - 1);
    }
};