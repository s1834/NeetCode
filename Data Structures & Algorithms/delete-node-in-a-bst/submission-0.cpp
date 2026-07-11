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
    TreeNode* minimum(TreeNode* root) {
        while(root->left) root = root->left;
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else {
             if(!root->left) {
                TreeNode* ptr = root->right;
                delete root;
                return ptr;
            }

            if(!root->right) {
                TreeNode* ptr = root->left;
                delete root;
                return ptr;
            }

            TreeNode* nxt = minimum(root->right);
            root->val = nxt->val;
            root->right = deleteNode(root->right, nxt->val);
        }
        return root;
    }
};