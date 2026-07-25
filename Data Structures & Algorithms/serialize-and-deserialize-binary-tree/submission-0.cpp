/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void preorder(TreeNode* root, string &serialized) {
        if(!root) {
            serialized += "n,";
            return;
        }

        serialized += to_string(root->val) + ",";

        preorder(root->left, serialized);
        preorder(root->right, serialized);
    }

    TreeNode* build(vector<string>& v, int& i) {
        if(v[i] == "n") {
            i++;
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(stoi(v[i]));
        i++;

        newNode->left = build(v, i);
        newNode->right = build(v, i);

        return newNode;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized = "";
        preorder(root, serialized);
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
        string temp = "";
        for(auto x : data) {
            if(x == ',') {
                v.push_back(temp);
                temp = "";
            } else temp += x;
        }
        
        int i = 0;
        return build(v, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));